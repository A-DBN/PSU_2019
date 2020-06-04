/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** returns a string reversed
*/

char *strrev(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i])
        i++;
    i--;
    while (j < i) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        j++;
        i--;
    }
    return (str);
}