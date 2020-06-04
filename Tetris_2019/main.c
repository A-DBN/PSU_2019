/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tetris.h"

int help(char **av)
{
    int fd;
    char buf[790];
    int size;

    my_putstr("Usage:  ");
    my_putstr(av[0]);
    my_putstr(" [options]");
    my_putchar('\n');
    fd = open("help", O_RDONLY);
    if (fd == -1)
        exit (84);
    size = read (fd, buf, 790);
    buf[size] = 0;
    my_putstr(buf);
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    tetris_t tetris;
    touch_t touch;

    if (ac == 2 && (my_strcmp(av[1], "--help") == 0)) {
        help(av);
    }
    else {
        if (option(ac, av, touch) == 84)
            return 84;
    }
    return (0);
}
