/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sandpile.h"

int main(int ac, const char **av)
{
    char *grid = NULL;
    int *grid_nb = NULL;

    if (ac != 4)
        return 84;
    grid = file_content(av[1]);
    if (grid == NULL)
        return 84;
    if (error(av, grid) == 84)
        return 84;
    grid_nb = malloc(sizeof(int) * (strlen(grid)));
    if (grid_nb == NULL)
        return 84;
    create_grid_nb(grid, grid_nb, av[2]);
    sandpile(grid, grid_nb, atoi(av[3]));
    //printf("%s", grid);
    free(grid);
    free(grid_nb);
    return 0;
}
