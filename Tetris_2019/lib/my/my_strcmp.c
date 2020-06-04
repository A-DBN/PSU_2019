/*
** EPITECH PROJECT, 2019
** day06
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return (s1[i] - s2[i]);
}