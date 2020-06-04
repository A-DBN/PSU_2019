/*
** EPITECH PROJECT, 2020
** my sh
** File description:
** mysh
*/

#include <mysh.h>
#include <my.h>

void my_exit(char **tab)
{
    int i = 0;

    my_putstr("exit\n");
    if (tab[1] != NULL && my_str_isnum(tab[1]) == 0) {
        i = my_getnbr(tab[1]);
        exit(i);
    }
    exit(i);
}

void print_env(char **copy)
{
    for (int i = 0; copy[i] != NULL; i++) {
        my_putstr(copy[i]);
        my_putchar('\n');
    }
}

int choose_option(char **tab, char **copy, char *buff)
{
    char cwd[256];
    /*void (*fct[2])(char **);

    fct[0] = print_env;
    fct[1] = my_exit;

    for (int i = 0; i < 2; ++i)
        fct[i](tab);
*/
    if (my_strcmp(tab[0], "env\n") == 0) {
        printf(tab[0]);
        //printf(my_strstr("/bin/", tab[0]));
        print_env(copy);
    }
    if (my_strcmp(tab[0], "cd") == 0)
        chdir(tab[1]);
    if (my_strcmp(tab[0], "exit") == 0 || my_strcmp(tab[0], "exit\n") == 0)
        my_exit(tab);
    if (my_strcmp(tab[0], "pwd\n") == 0) {
        getcwd(cwd, sizeof(cwd));
        my_putstr(cwd);
        my_putchar('\n');
    }
    exec(tab, copy);
    return (0);
}

int main(int ac,char **av, char **env)
{
    char **copy = env;
    size_t bufsiz = BUFSIZ;
    char *buff = malloc(sizeof(char) * bufsiz);
    char *b = buff;
    char **tab;

    if (ac != 1)
        return (84);
    while (1) {
        my_putstr("$> ");
        if (getline(&b,&bufsiz,stdin) == -1)
            exit(84);
        tab = my_str_to_word_array(buff, ' ');
        choose_option(tab, copy, buff);
    }
}
