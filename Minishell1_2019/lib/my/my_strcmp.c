/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}