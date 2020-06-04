/*
** EPITECH PROJECT, 10
** tetris
** File description:
** game.c
*/

#include "tetris.h"

void print_txt(tetris_t tetris)
{
    tetris.high_score = 0;
    tetris.score = 0;
    tetris.lines = 0;
    tetris.level = 0;
    tetris.timer = 0;

    mvprintw(5, 0, "  ******* ******* ******* ******* * *******\n");
    mvprintw(6, 0, "     *    *          *    *     *   *\n");
    mvprintw(7, 0, "     *    *******    *    ******  * *******\n");
    mvprintw(8, 0, "     *    *          *    *     * *       *\n");
    mvprintw(9, 0, "     *    *******    *    *     * * *******\n");
    mvprintw(15, 15, "/--------------------\\");
    mvprintw(16, 15, "|                    |");
    mvprintw(17, 15, "| High score     %i   |", tetris.high_score);
    mvprintw(18, 15, "| Score          %i   |", tetris.score);
    mvprintw(19, 15, "|                    |");
    mvprintw(20, 15, "| Lines          %i   |", tetris.lines);
    mvprintw(21, 15, "| Level          %i   |", tetris.level);
    mvprintw(22, 15, "|                    |");
    mvprintw(23, 15, "| Timer          %i   |", tetris.timer);
    mvprintw(24, 15, "\\--------------------/");
}

int game(touch_t *touch, tetris_t tetris)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    erase();
    while (1) {
        print_txt(tetris);
        printw("%s\n", touch->key_quit);
        if (getch() == touch->key_quit)
            break;
    }
    endwin();
    return 0;
}
