/*
** EPITECH PROJECT, 2019
** to_number
** File description:
** to_number
*/

void my_putchar(char c);

int my_getnbr(char const *str)
{
    int	nbr_sign = 0;
    int	nbr = 0;

    while (*str == '-' || *str == '+')
    {
        if (*str == '-')
            nbr_sign = nbr_sign * -1;
        str = str + 1;
    }
    while (*str != '\0' && *str >= '0' && *str <= '9') {
        if (nbr == 214748364 && *str > 7 && nbr_sign == 1)
            return (0);
        if (nbr == 214748364 && *str > 8 && nbr_sign == -1)
            return (0);
        nbr = nbr * 10 + *str - 48;
        str = str + 1;
    }
    if (nbr_sign == -1)
        nbr = nbr * -1;
    return (nbr);
}
