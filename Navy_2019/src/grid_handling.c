/*
** EPITECH PROJECT, 2020
** navy
** File description:
** boat_handling
*/

#include "navy.h"

void print_map(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            my_putchar(map[i][j]);
            if (i == 1)
                my_putchar('-');
            else
                my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

char **make_grid(void)
{
    char *s = file_to_str("assets/map");
    char **grid = ftsplit(s, '\n');

    free (s);
    return (grid);
}