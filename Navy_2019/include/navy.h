/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct boat {
    pos_t start;
    pos_t end;
    char *nb;
} boat_t;

void print_map(char **map);
int check_boats(char **boats);
int check_boats2(char **boats);
int freearray(void **array);
int get_userpid(int ac, char **av);
int gameloop(char **, char **);
void **freeturn(char *s, char **map, char **boats);
char **make_map(char *path);
char **make_grid(void);
pos_t coord_to_pos(char *coord);

#endif /* !NAVY_H_ */