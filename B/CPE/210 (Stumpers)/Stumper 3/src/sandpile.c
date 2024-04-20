/*
** EPITECH PROJECT, 2023
** sandpile.c
** File description:
** central loop
*/

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "sandpile.h"

static void add_grain(char *grid, int *grid_nb)
{
    size_t center = 0;

    center = strlen(grid);
    if (center == 1) {
        grid_nb[1] += 1;
        return;
    }
    if (center % 2 != 0) {
        center = (center - 1) / 2;
    } else {
        center = center / 2;
    }
    grid[center] += 1;
}

static void distribute_grains(char *grid, int *grid_nb, int index)
{
    int size = 0;

    while (grid_nb[size] != -1)
        size++;
    if (grid_nb[index] >= 4) {
        if (index + 1 != -1)
            grid_nb[index + 1] += 1;
        if (index > 1)
            grid_nb[index - 1] += 1;
        if (index + 1 + size < (int)strlen(grid))
            grid_nb[index + 1 + size] += 1;
        if (index - 1 - size > 0)
            grid_nb[index - 1 - size] += 1;
        grid_nb[index] -= 4;
    }
}

static void manage_unstable(char *grid, int *grid_nb)
{
    while (is_unstable(grid_nb)) {
        for (int i = 0; grid_nb[i]; i++) {
            distribute_grains(grid, grid_nb, i);
        }
    }
}

void sandpile(char *grid, int *grid_nb, int iterations)
{
    for (int i = 0; i <= iterations; i++) {
        add_grain(grid, grid_nb);
        manage_unstable(grid, grid_nb);
    }
}
