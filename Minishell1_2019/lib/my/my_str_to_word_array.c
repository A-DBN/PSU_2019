/*
** EPITECH PROJECT, 2020
** str to word array
** File description:
** str to word array
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_new_strlen(char *str)
{
    int z = 0;

    while (str[z] != '\0')
        z++;
    return (z);
}

int count_w(char *str, char c)
{
    int i = 0;
    int j = 0;

    for (; str[i] == c; i++);
    if (str[i] != c && str[i])
        j = 1;
    while (str[i]) {
        if (str[i] == c && str[i + 1] != c)
            j++;
        i++;
    }
    return (j);
}

int word_len(char *str, char c, int *pos)
{
    int len = 0;
    int i = *pos;

    for (; str[i] && str[i] == c; i++);
    if (str[i] == '\0')
        return (0);
    for (; str[i] && str[i] != c; i++, len++);
    *pos = i;
    return (len);
}

char **my_str_to_word_array(char *str, char c)
{
    int pos = 0;
    char **tab;
    int word = count_w(str, c);
    int len = 0;
    int j = 0;

    if (word == 0)
        return (NULL);
    tab = malloc(sizeof(char *) * word);
    for (int i = 0; i < word; i++) {
        len = word_len(str, c, &pos);
        j = pos - len;
        tab[i] = malloc(sizeof(char) * (len + 1));
        for (int d = 0; d < len; d++, j++)
            tab[i][d] = str[j];
        tab[i][len] = '\0';
    }
    return (tab);
}
