/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "stdarg.h"
#include "include/my.h"

int find_pourcent(char *str, int i)
{
    while (str[i] == '%')
        i++;
    return (i);
}

int post_pourcent(char flag, va_list list, int i)
{
    char *str;

    switch(flag){
        case 'd':
            my_put_nbr(va_arg(list, int));
            break;
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 's':
            str = (char *) va_arg(list, char *);
            my_putstr(str);
            break;
        case 'u':
            my_put_nbr(va_arg(list, int));
            break;
    }
}

int my_printf(char *str, ...)
{
    int i = 0;
    char flag = 0;
    int n = 0;
    va_list list;
    va_start(list, str);

    while (str[i] != '\0') {
        if (str[i] == '%') {
            i = find_pourcent(str ,i);
            flag = str[i];
            post_pourcent(flag, list, i);
            i++;
        }
        if (str[i - 1] != '%') {
            my_putchar(str[i]);
            n++;
        }
        i++;
    }
    va_end(list);
    return i;
}
