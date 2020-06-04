/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count and return the nulber of characters
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        else if (s2[i] > s1[i])
            return (s1[i] - s2[i]);
        else
        i++;
    }
    return (0);
}
