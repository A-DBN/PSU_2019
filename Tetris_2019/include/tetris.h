/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ncurses.h>

typedef struct touch
{
    int level;
    char *key_left;
    char *key_turn;
    char *key_right;
    char *key_quit;
    char *key_pause;
    char *key_drop;
    char *next;
}touch_t;

typedef struct tetris
{
    int high_score;
    int score;
    int lines;
    int level;
    int timer;
}tetris_t;

void my_putchar(char c);
int my_putstr(char const *str);
void my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int option(int ac, char **av, touch_t touch);
void debug(touch_t *touch);
int game(touch_t *touch, tetris_t tetris);
void print_txt(tetris_t tetris);

#endif /* !TETRIS_H_ */
