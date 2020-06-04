/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count and return the nulber of characters
*/

int my_strlen(char const *str)
{
    int i;

    i=0;
    while (*str != '\0')
    {
        *str++;
        i++;
    }
    return (i);
}
