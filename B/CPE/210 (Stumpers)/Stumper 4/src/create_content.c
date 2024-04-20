/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file of the project
*/

#include <stdlib.h>
#include "mixword.h"

int create_content(const char *av[], int size)
{
    char *buffer = NULL;
    char **array = NULL;
    char **grid = NULL;

    buffer = file_content(av[2]);
    if (buffer == NULL)
        return 84;
    if (is_lowercase(buffer) == false)
        return 84;
    array = my_tokarray(buffer, "\n");
    if (array == NULL)
        return 84;
    grid = create_grid(array, size);
    if (grid == NULL)
        return 84;
    print_grid(grid, array, size);
    free(buffer);
    free_array(array);
    free_array(grid);
    return 0;
}
