/*
** EPITECH PROJECT, 2019
** my_newstrstr
** File description:
** new_strstr
*/

#include "include/my.h"

char *my_newstrstr(char *str, char *str2)
{
    char *ret;
    int i = 0;
    int j = 0;

    if (str == NULL || str2 == NULL)
        return (NULL);
    ret = malloc(sizeof(char) * (my_strlen(str) + my_strlen(str2) + 2));
    while (str[i] != '\0') {
        ret[i] = str[i];
        i++;
    }
    str[i] = '/';
    i++;
    while (str2[j] != '\0') {
        ret[i] = str2[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    return ret;
}
