/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-dante-benjamin.gayaud
** File description:
** solver.c
*/

#include <stdio.h>
#include "solver.h"

int solver(char **map, char **map_cpy, char *buffer)
{
    int x = 0, y = 0, moved = 0, turns = 0;
    int nbline = nb_line(buffer); int nbcol = nb_col(buffer);
    int total = (nbline * 4) * (nbcol * 4);

    while ((x != nbline - 1 || y != nbcol - 1) && turns < total) {
        if (moved == 0 && (moved = mv_right(map, moved, x, y)) == 1) y++;
        if (moved == 0 && (moved = mv_bottom(map, moved, x, y)) == 1) x++;
        if (moved == 0 && (moved = mv_left(map, moved, x, y)) == 1) y--;
        if (moved == 0 && (moved = mv_top(map, moved, x, y)) == 1) x--;
        if (moved == 0 && (moved = mv_right2(map, moved, x, y)) == 1) y++;
        if (moved == 0 && (moved = mv_bottom2(map, moved, x, y)) == 1) x++;
        if (moved == 0 && (moved = mv_left2(map, moved, x, y)) == 1) y--;
        if (moved == 0 && (moved = mv_top2(map, moved, x, y)) == 1) x--;
        turns++; moved = 0;
    }
    if (turns >= total) {
        printf("no solution found"); return 0;
    }
    convert_maze(map, map_cpy);
    return 0;
}
