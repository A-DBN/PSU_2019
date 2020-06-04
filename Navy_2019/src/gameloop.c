/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** gameloop
*/

#include "navy.h"

int player_turn(char **p_grid, char **hit_grid)
{
    char *input = NULL;
    int i;
    size_t len;

    putstr("my positions:\n");
    print_map(p_grid);
    putstr("enemy's positions:\n");
    print_map(hit_grid);
    putstr("attack: ");
    i = getline(&input, &len, stdin);
    if (i == -1)
        return (84);
    write(1, input, my_strlen(input) - 1);
    putstr(": hit\n");
    return (0);
}

int gameloop(char **p_grid, char **hit_grid)
{
    player_turn(p_grid, hit_grid);
    return (0);
}