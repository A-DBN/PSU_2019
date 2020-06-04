/*
** EPITECH PROJECT, 2020
** put_nbr
** File description:
** put_nbr
*/

#include "include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while (nb >= 0) {
        if (nb >= 10)
            my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
        return (0);
    }
}
