/*
** EPITECH PROJECT, 2020
** cleanstr
** File description:
** cleanstr
*/

#include "include/my.h"

char *my_cleanstr(char *str)
{
    int i = 0;
    int j = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0') {
        if (str[i] == 9)
            str[i] = ' ';
        newstr[j] = str[i];
        i++;
        j++;
    }
    newstr[i] = '\0';
    return newstr;
}
