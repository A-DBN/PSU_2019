/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** prints a string
*/

#include "my.h"

void putstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}