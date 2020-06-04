/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display one by one characters of a string
*/

#include "../../include/tetris.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\\' && str[i + 1] == 'n') {
            my_putchar('\n');
            i = i + 2;
        }
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
