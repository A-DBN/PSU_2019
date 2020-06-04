/*
** EPITECH PROJECT, 2020
** my.H
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
char *my_strstr(char *str, char *str2);
char **my_str_to_word_array(char *str, char c);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int my_strcmp(char *s1, char *s2);
char *my_cleanstr(char *str);
int my_strncmp(char *s1, char *s2, int n);
char *my_newstrstr(char *str, char *str2);
int sal(char const *str);

#endif /* MY_H_ */
