/*
** EPITECH PROJECT, 2019
** day09
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);
void putstr(char *str);
void putnbr(int nb);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_atoi(char const *str);
char *my_strlowcase(char *str);
char *my_itoa(int nb);
char *strrev(char *str);
char *my_strcat(char *dest, char const *src);
char *file_to_str(char const *path);
char **ftsplit(char *s, char d);

#endif /* !MY_H_ */