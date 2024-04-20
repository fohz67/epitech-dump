/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-dante-benjamin.gayaud
** File description:
** mv_hard.c
*/

#include <stdlib.h>
#include "solver.h"

int mv_top2(char **map, int moved, int x, int y)
{
    if (moved == 0 && x - 1 != -1 && map[x - 1] != NULL &&
    map[x - 1][y] != 'X') {
        if (map[x - 1][y] == '#') {
            map[x][y] = 'X';
        } else {
            map[x - 1][y] = '#';
        }
        moved = 1;
    }
    return moved;
}

int mv_left2(char **map, int moved, int x, int y)
{
    if (moved == 0 && y - 1 != -1 && map[x][y - 1] != 'X') {
        if (map[x][y - 1] == '#') {
            map[x][y] = 'X';
        } else {
            map[x][y - 1] = '#';
        }
        moved = 1;
    }
    return moved;
}

int mv_bottom2(char **map, int moved, int x, int y)
{
    if (moved == 0 && map[x + 1] != NULL && map[x + 1][y] != 'X') {
        if (map[x + 1][y] == '#') {
            map[x][y] = 'X';
        } else {
            map[x + 1][y] = '#';
        }
        moved = 1;
    }
    return moved;
}

int mv_right2(char **map, int moved, int x, int y)
{
    if (moved == 0 && map[x][y + 1] != '\0' && map[x][y + 1] != 'X' &&
    map[x][y + 1] != '\n') {
        if (map[x][y + 1] == '#') {
            map[x][y] = 'X';
        } else {
            map[x][y + 1] = '#';
        }
        moved = 1;
    }
    return moved;
}
