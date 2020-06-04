/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban
*/

#include <stdlib.h>
#include <ncurses.h>
#include "struct.h"
#include "my.h"
#include "string.h"

int main(int ac, char **av);

void main_move(soko_t *soko);

void get_pos(soko_t *soko)
{
    //soko->pos = 0;
    while (soko->buff[soko->pos] != 'P')
        soko->pos++;
}

int check_map(soko_t *soko)
{
    int k = 0;
    int w = 0;

    while (soko->buff[w] != '\0') {
        if (soko->buff[w] == 'X')
            k++;
        /*if (soko->buff[w] != 'P' && soko->buff[w] != '#' &&
         soko->buff[w] != 'X' && soko->buff[w] != 'O')
            return (1);*/
    }
    if (k == 0)
        return (0);
}

int window(soko_t *soko, int ac, char **av)
{
    int i = 0;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    printw("%s", soko->buff);
    get_pos(soko);
    soko->keep_buff = soko->buff;
    while (soko->key != 27) {
        soko->key = getch();
        erase();
        main_move(soko);
        printw("%s", soko->buff);
        refresh();
        //check_map(soko);
    }
    endwin();
}
