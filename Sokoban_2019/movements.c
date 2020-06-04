/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban
*/

#include "struct.h"
#include "ncurses.h"

void move_l(soko_t *soko)
{
    if (soko->buff[soko->pos - 1] == ' ') {
        soko->buff[soko->pos] = ' ';
        soko->pos--;
        soko->buff[soko->pos] = 'P';
    }
    if (soko->buff[soko->pos - 1] == 'O' && soko->buff[soko->pos - 2] != '#') {
        soko->buff[soko->pos] = ' ';
        soko->buff[soko->pos - 2] = 'O';
        soko->pos--;
        soko->buff[soko->pos] = 'P';
    }
}

void move_r(soko_t *soko)
{
    if (soko->buff[soko->pos + 1] == ' ') {
        soko->buff[soko->pos] = ' ';
        soko->pos++;
        soko->buff[soko->pos] = 'P';
    }
    if (soko->buff[soko->pos + 1] == 'O' && soko->buff[soko->pos + 2] != '#') {
        soko->buff[soko->pos] = ' ';
        soko->buff[soko->pos + 2] = 'O';
        soko->pos++;
        soko->buff[soko->pos] = 'P';
    }
}

void move_up(soko_t *soko)
{
    int j = 26;
    if (soko->buff[soko->pos - 13] == ' ') {
        soko->buff[soko->pos] = ' ';
        soko->pos -= 13;
        soko->buff[soko->pos] = 'P';
    }
    if (soko->buff[soko->pos - 13] == 'O' && soko->buff[soko->pos - j] != '#') {
        soko->buff[soko->pos] = ' ';
        soko->buff[soko->pos - 26] = 'O';
        soko->pos -= 13;
        soko->buff[soko->pos] = 'P';
    }
}

void move_down(soko_t *soko)
{
    int i = 26;

    if (soko->buff[soko->pos + 13] == ' ') {
        soko->buff[soko->pos] = ' ';
        soko->pos += 13;
        soko->buff[soko->pos] = 'P';
    }
    if (soko->buff[soko->pos + 13] == 'O' && soko->buff[soko->pos + i] != '#') {
        soko->buff[soko->pos] = ' ';
        soko->buff[soko->pos + 26] = 'O';
        soko->pos += 13;
        soko->buff[soko->pos] = 'P';
    }
}

int main_move(soko_t *soko)
{
    switch(soko->key) {
    case 261:
        move_r(soko);
        break;
    case 260:
        move_l(soko);
        break;
    case 258:
        move_down(soko);
        break;
    case 259:
        move_up(soko);
        break;
    case 32:
        soko->buff == soko->keep_buff;
        break;
    }
    return (0);
}
