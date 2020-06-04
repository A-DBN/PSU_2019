/*
** EPITECH PROJECT, 2020
** my sh
** File description:
** mysh
*/

#include <mysh.h>

void my_exit(char **tab, char **copy)
{
    int i = 0;

    if (tab[1] != NULL && my_str_isnum(tab[1]) == 1) {
        i = my_getnbr(tab[1]);
        my_putstr("exit\n");
        free(tab);
        exit(i);
    } else if (tab[1] != NULL && my_str_isnum(tab[1]) == 0) {
        my_putstr("exit: Expression Syntax.\n");
    } else {
        my_putstr("exit\n");
        free(tab);
        exit(0);
    }
}

void env(char **tab, char **copy)
{
    for (int i = 0; copy[i] != NULL; i++) {
        my_putstr(copy[i]);
        my_putchar('\n');
    }
}

void change_dir(char **tab, char **copy)
{
    char **change;
    int h = 0;

    if (tab[1] != NULL && tab[1][0] == 45) {
        chdir(find_pwd(copy));
    }
    while (copy[h] != NULL) {
        if (my_strncmp(copy[h], "HOME", 4) == 0)
            change = my_str_to_word_array(copy[h], '=');
        h++;
    }
    if (tab[1] != NULL) {
        if (chdir(tab[1]) == -1) {
            my_putstr(tab[1]);
            my_putstr(": No such file or directory.\n");
        }
    } else {
        chdir(change[1]);
    }
    free(change);
}

void choose_option(char **tab, char **copy, char *b)
{
    int i = 0;
    void (*fct[4])(char **, char **) = {env, my_exit, change_dir, my_unsetenv};
    char *contain[4] = {"env", "exit", "cd", "unsetenv"};
    int (*fct_r[2])(char *, char **, char **) = {redirect_rr, redirect_r};
    char *contain_r[2] = {">>", ">\0"};

    for (; i < 4; ++i) {
        if (my_strcmp(tab[0], contain[i]) == 0)
            (*fct[i])(tab, copy);
    }
    i = 0;
    for (; i < 2 && tab[1] != NULL; i++) {
        if (my_strcmp(tab[1], contain_r[i]) == 0)
            (*fct_r[i])(b, copy, tab);
    }
    if (my_strcmp(tab[0], "setenv") == 0)
        my_setenv(tab, copy);
    if (my_strcmp(tab[0], "env") != 0 && my_strncmp(tab[0], "cd", 2) != 0 &&
    my_strcmp(tab[0], "setenv") != 0 && my_strcmp(tab[0], "unsetenv") != 0 &&
    my_strcmp(tab[0], "exit") != 0)
        exec_cmd(tab, copy);
}

int main(int ac, char **av, char **env)
{
    char **copy = env;
    size_t bufsiz = BUFSIZE;
    char *b = NULL;
    int nb = 0;
    char **tab;

    signal(SIGINT, ctrl_c);
    errors_main(ac, av);
    while (1) {
        my_putstr("$> ");
        bufsiz = BUFSIZE;
        if ((nb = getline(&b, &bufsiz, stdin)) == -1) {
            my_putstr("exit\n");
            return 0;
        }
        if (nb == 1 || (nb == 2 && b[0] == ' '))
            main(ac, av, env);
        tab = transform(nb, b, tab, copy);
        choose_option(tab, copy, b);
    }
    my_free(tab, copy);
}
