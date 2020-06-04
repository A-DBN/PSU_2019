/*
** EPITECH PROJECT, 2020
** debug.c
** File description:
** debug
*/
#include "include/tetris.h"

void put_line(char *str1, char *str2)
{
    my_putstr(str1);
    my_putstr(str2);
    my_putchar('\n');
}

void debug2(void)
{
    my_putstr("Tetriminos :  7\n");
    my_putstr("Tetriminos :  Name 4 :  Error\n");
    my_putstr("Tetriminos :  Name 5 :  Size 1*1 :  Color 4 :\n*\n");
    my_putstr("Tetriminos :  Name 6 :  Size 2*3 :  Color 6 :\n *\n**\n*\n");
    my_putstr("Tetriminos :  Name 7 :  Size 5*4 :  Color 3 :");
    my_putstr("\n * *\n* * *\n * *\n  *\n");
    my_putstr("Tetriminos :  Name bar :  Size 1*4 :  Color 2 :\n*\n*\n*\n*\n");
    my_putstr("Tetriminos :  Name inverted-L : Size 2*3 :  Color 5 :");
    my_putstr("\n *\n *\n**\n");
    my_putstr("Tetriminos :  Name square :  Size 2*2 :  Color 1 :\n**\n**\n");
    my_putstr("Press any key to start Tetris\n");
}

void debug(touch_t *touch)
{
    my_putstr("*** DEBUG MODE ***\n");
    put_line("Key Left :  ", touch->key_left);
    put_line("Key Right :  ", touch->key_right);
    put_line("Key Turn :  ", touch->key_turn);
    put_line("Key Drop :  ", touch->key_drop);
    put_line("Key Quit :  ", touch->key_quit);
    put_line("Key Pause :  ", touch->key_pause);
    put_line("Next :  ", touch->next);
    my_putstr("Level :  ");
    my_put_nbr(touch->level);
    my_putchar('\n');
    my_putstr("Size :  20*10\n");
    debug2();
}
