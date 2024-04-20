/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <string.h>
#include <stdbool.h>
#include "sandpile.h"

static const int MIN_SIZE_GRID = 1;
static const int NB_VALUES = 4;

static bool is_rectangle_map(char *grid)
{
    int first_len = 0;
    int line_len = 0;

    for (int i = 0; grid[i] != '\0'; i++) {
        if (grid[i] == '\n') {
            first_len = i;
            break;
        }
    }
    for (int i = 0; grid[i] != '\0'; i++) {
        if (grid[i] == '\n' && first_len != line_len) {
            return false;
        }
        if (grid[i] == '\n') {
            line_len = 0;
        } else {
            line_len++;
        }
    }
    return true;
}

static bool is_map_valid(char *grid, const char *template)
{
    if ((int)strlen(grid) < MIN_SIZE_GRID) {
        return false;
    }
    for (int i = 0; grid[i] != '\0'; i++) {
        if (grid[i] != template[0] &&
            grid[i] != template[1] &&
            grid[i] != template[2] &&
            grid[i] != template[3] &&
            grid[i] != '\n') {
            return false;
        }
    }
    return true;
}

static bool is_only_digit(const char *template)
{
    if ((int)strlen(template) != NB_VALUES) {
        return false;
    }
    for (int i = 0; template[i] != '\0'; i++) {
        if (template[i] < '0' || template[i] > '9') {
            return false;
        }
    }
    return true;
}

int error(const char **av, char *grid)
{
    if (is_only_digit(av[2]) == false) {
        return 84;
    }
    if (is_map_valid(grid, av[2]) == false) {
        return 84;
    }
    if (is_rectangle_map(grid) == false) {
        return 84;
    }
    return 0;
}
