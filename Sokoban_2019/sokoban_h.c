/*
** EPITECH PROJECT, 2019
** sokoban_h
** File description:
** sokoban_h
*/

#include <ncurses.h>
#include "my.h"

void sokoban_h(int ac, char **av)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehousemap, containing '#'");
    my_putstr(" for walls,\n        'P' for the player, 'X' for boxes and ");
    my_putstr("'O' for storage locations.\n");
}
