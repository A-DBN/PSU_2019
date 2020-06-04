/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** converts a string to an int
*/

#include "my.h"

int my_atoi(char const *str)
{
    int nb = 0;
    int i = 0;
    int overflow_checker;
    int minus = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str [i] == '-')
            minus *= -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0') {
        overflow_checker = nb;
        nb = nb * 10 + (str[i] - 48);
        if (nb == 214748364 && str[i + 1] == '8' && minus > 0)
            return (0);
        if (nb / 10 != overflow_checker && nb != -2147483648)
            return (0);
        i++;
    }
    return (minus * nb);
}

int count(int nb)
{
    int i = 0;
    int u = 0;
    int great = 1;

    if (nb < 0) {
        nb *= -1;
        u++;
    }
    while (great <= nb) {
        great *= 10;
        i++;
    }
    i += u;
    return (i);
}

char *itoa_main(int nb)
{
    int nb_char = count(nb);
    char *str = malloc((nb_char + 1) * sizeof(char));
    int i = 0;
    int new_nb = 0;

    str[nb_char] = '\0';
    if (nb < 0)
        new_nb = nb * -1;
    else
        new_nb = nb;
    while (i < nb_char) {
        str[i] = (new_nb % 10) + 48;
        i++;
        new_nb /= 10;
    }
    if (nb < 0)
        str[i - 1] = '-';
    str = strrev(str);
    return (str);
}

char *my_itoa(int nb)
{
    if (itoa_main(nb)[0] != '\0')
        return (itoa_main(nb));
    else
        return ("0");
}