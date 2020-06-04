/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** _to_tab
*/

#include "my.h"

int field_count(char *s, char d)
{
    int i = 0;
    int f = 0;

    for (; s[i] == d; i++);
    if (s[0] != d)
            f = 1;
    for (; s[i + 1]; i++)
        if (s[i] == d && s[i + 1] != d)
            f++;
    return (f);
}

int field_len(char *s, int *currentpos, char d)
{
    int len = 0;
    int i = *currentpos;

    for (; s[i] && s[i] == d; i++);
    if (s[i] == '\0')
        return (0);
    for (; s[i] && s[i] != d; i++, len++);
    *currentpos = i;
    return (len);
}

char **ftsplit(char *s, char d)
{
    char **tab = NULL;
    int i;
    int wrdlen;
    int pos = 0;
    int fields;

    fields = field_count(s, d);
    if (fields == 0)
        return (NULL);
    tab = malloc((fields + 1) * sizeof(char *));
    tab[fields] = NULL;
    for (int y = 0; y < fields; y++) {
        wrdlen = field_len(s, &pos, d);
        i = pos - wrdlen;
        tab[y] = malloc((wrdlen + 1) * sizeof(char));
        for (int x = 0; x < wrdlen; x++, i++)
            tab[y][x] = s[i];
        tab[y][wrdlen] = '\0';
    }
    return (tab);
}