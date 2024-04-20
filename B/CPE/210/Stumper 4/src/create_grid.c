/*
** EPITECH PROJECT, 2023
** create_grid.c
** File description:
** alloc and fill the grid.
*/

#include <stdlib.h>
#include "mixword.h"

static char get_random_letter(void)
{
    char c = 97;

    c += rand() % 26;
    return c;
}

static char **alloc_array(int size)
{
    char **array = NULL;
    int j = 0;

    array = malloc(sizeof(char *) * (size + 1));
    if (!array) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(char) * (size + 1));
        if (!array[i]) {
            return NULL;
        }
        for (j = 0; j < size; j++) {
            array[i][j] = get_random_letter();
        }
        array[i][j] = '\0';
    }
    array[size] = NULL;
    return array;
}

static char **fill_line(const char *word, char **grid, int line)
{
    int i = 0;

    for (; word[i] != '\0'; i++) {
        grid[line][i] = word[i];
    }
    return grid;
}

static char **fill_grid(char **array, char **grid, int size)
{
    int line_filled = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (my_strlen(array[i]) <= size) {
            grid = fill_line(array[i], grid, line_filled);
            line_filled++;
        } else {
            return NULL;
        }
        if (line_filled == size) {
            return grid;
        }
    }
    return grid;
}

char **create_grid(char **array, int size)
{
    char **grid = NULL;

    grid = alloc_array(size);
    if (!grid) {
        return NULL;
    }
    grid = fill_grid(array, grid, size);
    return grid;
}
