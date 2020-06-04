/*
** EPITECH PROJECT, 2020
** exec.c
** File description:
** exec.c
*/

#include "my.h"
#include "mysh.h"

int exec(char **tab, char **copy)
{
    int pid = getpid();
    char *foo[] = {tab[1]};

     if ((pid = fork()) == 0) {
        execve(my_strstr("/bin/", tab[0]), foo, copy);
        exit (0);
    } else {
        wait(NULL);
    }
    return (0);
}
