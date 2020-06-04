/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** redirec.c
*/

#include "mysh.h"

int find_symb(char **tab)
{
    int i = 0;

    while (1) {
        if (my_strncmp(tab[i], ">>", 1) == 0)
            return (i + 1);
        i++;
    }
    return (i + 1);
}

char *cut_string(char *b, char c)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(b));

    while (b[i] != c) {
        new_str[i] = b[i];
        i++;
    }
    new_str[i] = '\0';
    i = 0;
    free(b);
    b = NULL;
    b = malloc(sizeof(char) * my_strlen(new_str) + 1);
    while (new_str[i] != '\0') {
        b[i] = new_str[i];
        i++;
    }
    b[i] = '\0';
    free(new_str);
    new_str = NULL;
    return b;
}

void exec_my_cmd(char *str, char **copy)
{
    char **exec_env = my_str_to_word_array(find_path(copy), ':');
    char **tab = my_str_to_word_array(str, ' ');
    char *contain = my_strstr("/bin/", tab[0]);
    int nb = 0;

    if (access(contain, F_OK) == 0 || access(tab[0], F_OK) == 0) {
        if (my_strncmp(tab[0], "/bin", 4) == 0)
            nb = execve(tab[0], tab, exec_env);
        else
            nb = execve(my_strstr("/bin/", tab[0]), tab, exec_env);
    } else {
        my_putstr(tab[0]);
        my_putstr(": command not found.\n");
    }
    free(tab);
    exit(0);
}

int redirect_rr(char *b, char **copy, char **tab)
{
    pid_t child;
    int fd;
    int symb = find_symb(tab);
    int save;
    char *str = cut_string(b, '>');

    if (tab[symb] != NULL) {
        if ((fd = open(tab[2], O_CREAT | O_WRONLY
        | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
            return 84;
        if ((child = fork()) == 0) {
            dup2(fd, 1);
            exec_my_cmd(str, copy);
            exit(child);
        } else {
            wait(NULL);
        }
    }
    free(str);
    return 0;
}

int redirect_r(char *b, char **copy, char **tab)
{
    pid_t child;
    int fd;
    int symb = find_symb(tab);
    int save;
    char *str = cut_string(b, '>');

    if (tab[symb] != NULL) {
        if ((fd = open(tab[2], O_CREAT | O_WRONLY
        | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
            return 84;
        if ((child = fork()) == 0) {
            dup2(fd, 1);
            exec_my_cmd(str, copy);
            exit(child);
        } else {
            wait(NULL);
        }
        close(fd);
    }
    free(str);
    return 0;
}
