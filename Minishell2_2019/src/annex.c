/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** annex.c
*/

#include "mysh.h"

void ctrl_c(int i)
{
    if (i == 2)
        my_putstr("\n$> ");
}

char *final_changeline(char **tab, char *stock, int p)
{
    stock[p] = '=';
    stock[p + 1] = '\0';
    stock = my_strstr(stock, tab[2]);
    stock[my_strlen(stock)] = '\0';
    return stock;
}

char *find_pwd(char **copy)
{
    char **stock_pwd;
    int v = 0;

    while (copy[v] != NULL) {
        if (my_strncmp(copy[v], "OLDPWD", 6)) {
            stock_pwd = my_str_to_word_array(copy[v], '=');
        }
        v++;
    }
    return stock_pwd[1];
}

char *next_add_line(char **tab, int d, int t , char **copy)
{
    copy[d] = malloc(sizeof(char) * (my_strlen(tab[1]) + 2));

    while (tab[1][t] != '\0') {
        copy[d][t] = tab[1][t];
        t++;
    }
    copy[d][t] = '=';
    t++;
    copy[d][t] = '\0';
    return copy[d];
}

char  **transform(int nb, char *b, char **tab, char **copy)
{
    b[nb - 1] = '\0';
    b = my_cleanstr(b);
    tab = my_str_to_word_array(b, ' ');
    free(b);
    b = NULL;
    return tab;
}
