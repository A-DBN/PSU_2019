/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** print an int type variable
*/

#include "my.h"

void putnbr(int nb)
{
    if (nb < 0)
    {
        putchar('-');
        if (nb == -2147483648)
        {
            putchar('2');
            nb = -147483648;
        }
        nb *= -1;
    }
    if (nb < 10)
        putchar(nb + 48);
    else
    {
        putnbr(nb / 10);
        putchar(nb % 10 + 48);
    }
}