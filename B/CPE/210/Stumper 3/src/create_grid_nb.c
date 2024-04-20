/*
** EPITECH PROJECT, 2022
** create_grid_nb.c
** File description:
** create_grid_nb.c
*/

#include <stdio.h>
#include "sandpile.h"

static int get_nb_grid(const char c, const char *template)
{
    int nb = 0;

    if (c == template[0]) {
        nb = 0;
    }
    if (c == template[1]) {
        nb = 1;
    }
    if (c == template[2]) {
        nb = 2;
    }
    if (c == template[3]) {
        nb = 3;
    }
    if (c == '\n') {
        nb = -1;
    }
    return nb;
}

void create_grid_nb(char *grid, int *grid_nb, const char *template)
{
    for (int i = 0; grid[i] != '\0'; i++) {
        grid_nb[i] = get_nb_grid(grid[i], template);
        printf("%d", grid_nb[i]);
    }
}
