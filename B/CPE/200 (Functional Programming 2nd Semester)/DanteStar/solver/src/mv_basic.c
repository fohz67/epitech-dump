/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-dante-benjamin.gayaud
** File description:
** mv_basic.c
*/

#include <stdlib.h>
#include "solver.h"

int mv_top(char **map, int moved, int x, int y)
{
    if (moved == 0 && x - 1 != -1 && map[x - 1] != NULL &&
    map[x - 1][y] != 'X' && map[x - 1][y] != '#') {
        if (map[x - 1][y] == '#') {
            map[x][y] = 'X';
        } else {
            map[x - 1][y] = '#';
        }
        moved = 1;
    }
    return moved;
}

int mv_left(char **map, int moved, int x, int y)
{
    if (moved == 0 && y - 1 != -1 && map[x][y - 1] != 'X'
    && map[x][y - 1] != '#') {
        if (map[x][y - 1] == '#') {
            map[x][y] = 'X';
        } else {
            map[x][y - 1] = '#';
        }
        moved = 1;
    }
    return moved;
}

int mv_bottom(char **map, int moved, int x, int y)
{
    if (moved == 0 && map[x + 1] != NULL && map[x + 1][y] != 'X'
    && map[x + 1][y] != '#') {
        if (map[x + 1][y] == '#') {
            map[x][y] = 'X';
        } else {
            map[x + 1][y] = '#';
        }
        moved = 1;
    }
    return moved;
}

int mv_right(char **map, int moved, int x, int y)
{
    if (moved == 0 && map[x][y + 1] != '\0' && map[x][y + 1] != 'X' &&
    map[x][y + 1] != '\n' && map[x][y + 1] != '#') {
        if (map[x][y + 1] == '#') {
            map[x][y] = 'X';
        } else {
            map[x][y + 1] = '#';
        }
        moved = 1;
    }
    return moved;
}
