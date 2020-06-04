/*
** EPITECH PROJECT, 2020
** my.H
** File description:
** my.h
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include <dirent.h>
#include <limits.h>
#include <fcntl.h>
#include <signal.h>
#include "my.h"

#ifndef MY_SH_
#define MY_SH_
#define BUFSIZE 0

int exec_cmd(char **tab, char **copy);
char **my_setenv(char **copy, char **tab);
void my_unsetenv(char **copy, char **tab);
char **transform(int nb, char *b, char **tab, char **copy);
void choose_option(char **tab, char **copy, char *b);
int redirect_rr(char *b, char **copy, char **tab);
int redirect_r(char *b, char **copy, char **tab);
char *next_add_line(char **tab, int d, int t , char **copy);
char *final_changeline(char **tab, char *stock, int p);
char *find_pwd(char **copy);
void ctrl_c(int i);
char *find_path(char **copy);
int print_error(char **tab);
int count_bis(int j, int i, char **copy);
char *env_bis(int d, int t, char **tab, char **copy);
void my_free(char **tab, char **copy);
int errors_main(int ac, char **av);
int my_strcmp_equal(char *s1, char *s2);

#endif /* MY_SH_ */
