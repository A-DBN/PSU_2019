/*
** EPITECH PROJECT, 2020
** navy
** File description:
** errcheck
*/

#include "navy.h"

int check_boats(char **boats)
{
    for (int i = 0; i < 4; i++) {
        if (boats[i][0] != i + 2 + 48)
            return (84);
        if (boats[i][1] != ':' || boats[i][4] != ':')
            return (84);
        if (!('A' <= boats[i][2] && boats[i][2] <= 'H'))
            return (84);
        if (!('1' <= boats[i][3] && boats[i][3] <= '8'))
            return (84);
        if (!('A' <= boats[i][5] && boats[i][5] <= 'H'))
            return (84);
        if (!('1' <= boats[i][6] && boats[i][6] <= '8'))
            return (84);
        if (boats[i][2] != boats[i][5] && boats[i][3] != boats[i][6])
            return (84);
    }
    return (0);
}

int check_boats2(char **boats)
{
    char start;
    char end;
    int dir = 0;

    for (int i = 0; i < 4; i++) {
        if (boats[i][2] != boats[i][5]) {
            start = boats[i][2];
            end = boats[i][5];
        } else if (boats[i][3] != boats[i][6]) {
            start = boats[i][3];
            end = boats[i][6];
        }
        else
            return (84);
        dir = end - start > 0 ? 1 : -1;
        if ((end - start) * dir != i + 1)
            return (84);
    }
    return (0);
}

void **freeturn(char *s, char **map, char **boats)
{
    free (s);
    for (int i = 0; i < 10; i++)
        free(map[i]);
    free (map);
    for (int i = 0; i < 4; i++)
        free (boats[i]);
    free (boats);
    return (NULL);
}

int freearray(void **array)
{
    for (int i = 0; array[i]; i++)
        free (array[i]);
    free (array);
    return (0);
}