/*
** EPITECH PROJECT, 2019
** day08
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *dup;

    if (!(dup = malloc(len * sizeof(char))));
    for (int i = 0; i < len; i++)
        dup[i] = str[i];
    return (dup);
}