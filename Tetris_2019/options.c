/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** option.c
*/

#include "include/tetris.h"
#include <getopt.h>

void option2(int ac, char **av, touch_t touch)
{
    int d = 0;
    static struct option long_options[] = {
        {"level", required_argument, 0, 'L' },
        {"key-left", required_argument, 0, 'l' },
        {"key-right", required_argument, 0, 'r' },
        {"key-turn", required_argument, 0, 't' },
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q' },
        {"key-pause", required_argument, 0, 'p' },
        {"without-next", no_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'},
    };

    for (char c;(c = getopt_long(ac, av, "L:l:r:t:d:p:q:Dw",
     long_options, NULL)) != -1;) {
        switch (c) {
        case 'L': touch.level = atoi(optarg);
            break;
        case 'l': touch.key_left = optarg;
            break;
        case 'r': touch.key_right = optarg;
            break;
        case 't': touch.key_turn = optarg;
            break;
        case 'd': touch.key_drop = optarg;
            break;
        case 'p': touch.key_pause = optarg;
            break;
        case 'q': touch.key_quit = optarg;
            break;
        case 'D': d++;
            break;
        case 'w': touch.next = "Yes";
            break;
        }
    }
    if (d == 1)
        debug(&touch);
}

void test(touch_t *touch)
{
    touch->level = 1;
    touch->key_left = "^EOD";
    touch->key_turn = "^EOB";
    touch->key_right = "^EOC";
    touch->key_quit = "q";
    touch->key_pause = "(space)";
    touch->key_drop = "^EOA";
    touch->next = "No";
}

int option(int ac, char **av, touch_t touch)
{
    test(&touch);
    option2(ac, av, touch);
    return 0;
}
