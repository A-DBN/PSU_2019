/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
*/

#include "navy.h"
#include <time.h>
#include <sys/types.h>
#include <signal.h>

void handle_sigint(int sig)
{
    if (sig)
        sig += 0;
    putstr("ennemy connected\n");
}

int get_userpid(int ac, char **av)
{
    int n;
    struct timespec req = {req.tv_sec = 50, req.tv_nsec = 0};

    if (ac == 2) {
        putstr("my_pid:  ");
        n = getpid();
        putnbr(n);
        putchar('\n');
        putstr("waiting for enemy connection...\n\n");
        signal(SIGUSR1, handle_sigint);
        nanosleep(&req, NULL);
    }
    if (ac == 3) {
        putstr("my_pid:  ");
        n = getpid();
        putnbr(n);
        putchar('\n');
        kill(my_atoi(av[1]), SIGUSR1);
        putstr("successfully connected\n");
    }
    return (0);
}
