/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban
*/

#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "struct.h"


void sokoban_h(int ac, char **av);

int window(soko_t *soko, int ac, char **av);

size_t map_size(const char *file)
{
    struct stat st;
    if (stat(file, &st) != 0)
        return (0);
    return (st.st_size);
}

int main(int ac, char **av)
{
    int nb_bytes;
    soko_t *soko = malloc(sizeof(soko_t));

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        sokoban_h(ac, av);
    if (ac == 2) {
        soko->length = map_size(av[1]);
        soko->buff = malloc(sizeof(char) * (soko->length + 1));
        soko->buff[soko->length] =   '\0';
        soko->fd = open(av[1], O_RDWR);
        soko->key = 0;
        nb_bytes = read(soko->fd, soko->buff, soko->length);
    }
    if (soko->fd == -1 || nb_bytes == -1)
        return (84);
    window(soko, ac, av);
    free(soko->buff);
}
