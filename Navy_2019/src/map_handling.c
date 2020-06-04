/*
** EPITECH PROJECT, 2020
** navy
** File description:
** make_map
*/

#include "navy.h"

pos_t coord_to_pos(char *coord)
{
    pos_t pos;

    pos.x = coord[0] - 65 + 2;
    pos.y = coord[1] - 48 + 1;
    return (pos);
}

void swap_pos(pos_t *p1, pos_t *p2)
{
    pos_t tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int place_on_map(char **map, char boat_nb, pos_t start, pos_t end)
{
    for (; start.x < end.x; start.x++) {
        if (map[start.y][start.x] != '.')
            return (84);
        map[start.y][start.x] = boat_nb;
    }
    for (; start.y < end.y; start.y++) {
        if (map[start.y][start.x] != '.')
            return (84);
        map[start.y][start.x] = boat_nb;
    }
    map[start.y][start.x] = boat_nb;
    return (0);
}

int place_boats(char **map, char **boats)
{
    pos_t start;
    pos_t end;
    char **info_line;

    for (int i = 0; boats[i]; i++) {
        info_line = ftsplit(boats[i], ':');
        start = coord_to_pos(info_line[1]);
        end = coord_to_pos(info_line[2]);
        if (end.x < start.x || end.y < start.y)
            swap_pos(&start, &end);
        if (place_on_map(map, info_line[0][0], start, end))
            return (84);
        for (int j = 0; info_line[j]; j++)
            free(info_line[j]);
    }
    free(info_line);
    return (0);
}

char **make_map(char *str)
{
    int lines;
    char *s = file_to_str("assets/map");
    char **map = ftsplit(s, '\n');
    char **boats;

    for (lines = 0; map[lines]; lines++);
    if (lines != 10)
        return (NULL);
    boats = ftsplit(str, '\n');
    for (lines = 0; boats[lines]; lines++);
    if (lines != 4 || check_boats(boats) || check_boats2(boats))
        return (char **)(freeturn(s, map, boats));
    if (place_boats(map, boats))
        return (char **)(freeturn(s, map, boats));
    free (s);
    for (int i = 0; i < 4; i++)
        free (boats[i]);
    free (boats);
    return (map);
}