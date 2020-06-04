/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** annex_bis.c
*/

#include "mysh.h"

char *env_bis(int d, int t, char **tab, char **copy)
{
    int k = 0;

    while (tab[2][k] != '\0') {
        copy[d][t] = tab[2][k];
        t++;
        k++;
    }
    copy[d][t] = '\0';
    return copy[d];
}

int count_bis(int j, int i, char **copy)
{
    if (copy[i] != NULL) {
        while (copy[i][j] != '=')
            j++;
    }
    return j;
}

int print_error(char **tab)
{
    my_putstr(tab[0]);
    my_putstr(": Command not found.\n");
    return 0;
}

int errors_main(int ac, char **av)
{
    if (ac != 1)
        exit(84);
    return 0;
}

void my_free(char **tab, char **copy)
{
    free(copy);
    free(tab);
}
