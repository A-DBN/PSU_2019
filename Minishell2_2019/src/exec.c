/*
** EPITECH PROJECT, 2020
** exec.c
** File description:
** exec.c
*/

#include "mysh.h"

char *find_path(char **copy)
{
    int h = 0;

    while (copy[h] != NULL) {
        if (my_strncmp(copy[h], "PATH", 4) == 0)
            return copy[h];
        h++;
    }
    return copy[h];
}

int verif_exec(int nb, char **tab, char **exec_env)
{
    if (my_strncmp(tab[0], "/bin", 4) == 0)
        nb = execve(tab[0], tab, exec_env);
    else
        nb = execve(my_strstr("/bin/", tab[0]), tab, exec_env);
    return nb;
}

int exec_cmd(char **tab, char **copy)
{
    pid_t child;
    int nb = 0;
    char **exec_env = my_str_to_word_array(find_path(copy), ':');
    char *contain = my_strstr("/bin/", tab[0]);

    if (tab[1] != NULL && my_strncmp(tab[1], ">>", 1) == 0)
        return 0;
    if (access(contain, F_OK) == 0 || access(tab[0], F_OK) == 0) {
        if ((child = fork()) == 0) {
            nb = verif_exec(nb, tab, exec_env);
            exit (child);
        } else if (child < 0) {
            return 1;
        } else {
            wait(NULL);
        }
    } else {
        print_error(tab);
    }
    free(exec_env);
    return 0;
}

int my_strcmp_equal(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '=' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (-1);
        i++;
    }
    return (0);
}
