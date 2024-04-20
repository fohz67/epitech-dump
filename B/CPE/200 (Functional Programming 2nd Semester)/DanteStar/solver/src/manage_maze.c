/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-dante-benjamin.gayaud
** File description:
** convert_maze.c
*/

#include <stdlib.h>
#include "solver.h"

void change_char(char **map, char **map_cpy, int x, int y)
{
    if (map[x][y] == '#') {
        map_cpy[x][y] = 'o';
    }
}

void convert_maze(char **map, char **map_cpy)
{
    int x = 0;
    int y = 0;

    while (map[x] != NULL) {
        while (map[x][y] != '\0') {
            change_char(map, map_cpy, x, y);
            y++;
        }
        y = 0;
        x++;
    }
    map_cpy[0][0] = 'o';
    my_putarray(map_cpy);
}
