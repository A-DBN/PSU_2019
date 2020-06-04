/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** env.c
*/

#include "mysh.h"

int find_line(char **tab, char **copy)
{
    int m = 0;
    char **stock;

    while (copy[m] != NULL) {
        stock = my_str_to_word_array(copy[m], '=');
        if (my_strcmp(tab[1], stock[0]) == 0) {
            free(stock);
            return m;
        }
        free(stock);
        m++;
    }
    return m;
}

char *add_line(char **copy, char **tab, int d)
{
    int t = 0;

    if (tab[2] == NULL) {
        copy[d] = next_add_line(tab, d, t, copy);
        return copy[d];
    } else {
        copy[d] = malloc(sizeof(char) *
        (my_strlen(tab[2]) + my_strlen(tab[1]) + 2));
        while (tab[1][t] != '\0') {
            copy[d][t] = tab[1][t];
            t++;
        }
        copy[d][t] = '=';
        t++;
        copy[d] = env_bis(d, t, tab, copy);
    }
    return copy[d];
}

char *change_line(char **copy, char **tab, int i)
{
    int j = 0;
    int p = 0;
    char *stock = NULL;
    j = count_bis(j, i, copy);
    if (tab[2] == NULL)
        stock = malloc(sizeof(char) * j + 1);
    else
        stock = malloc(sizeof(char) * (j + my_strlen(tab[2]) + 2));
    if (copy[i] != NULL) {
        while (copy[i][p] != '=') {
            stock[p] = copy[i][p];
            p++;
        }
    }
    if (tab[2] == NULL) {
        stock[p] = '=';
        stock[p + 1] = '\0';
        return stock;
    } else {
        stock = final_changeline(tab, stock, p);
        return stock;
    }
}

char **my_setenv(char **tab, char **copy)
{
    int i = 0;
    int d = 0;

    if (tab[1] == NULL)
        return 0;
    for (int j = 0; j != 1; j++) {
        while (copy[d] != NULL)
            d++;
        i = find_line(tab, copy);
        if (tab[2] == NULL && i == d)
            add_line(copy, tab, d);
        else if (tab[2] != NULL && tab[3] == NULL && i == d)
            add_line(copy, tab, d);
        else
            copy[i] = change_line(copy, tab, i);
        copy[d + 1] = NULL;
    }
    return copy;
}

void my_unsetenv(char **tab, char **copy)
{
    for (int i = 0; copy[i] != NULL; i++) {
        if (my_strcmp_equal(copy[i], tab[1]) == 0) {
            copy[i] = copy[i + 1];
            return;
        }
    }
}
