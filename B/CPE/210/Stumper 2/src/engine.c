/*
** EPITECH PROJECT, 2023
** engine.c
** File description:
** engine.c
*/

#include <stdio.h>
#include "ginger.h"

static int get_pos_point(char **map, int *coords_saved, int x, int y)
{
    if (map[x][y] != '.' && map[x][y] != '\n') {
    }
    return 0;
}

static int get_next_point(char **map, int *coords_saved)
{
    int x = 0;
    int y = 0;

    while (map[x] != NULL) {
        while (map[x][y] != '\0') {
            get_pos_point(map, coords_saved, x, y);
            y++;
        }
        x++;
    }
    return 0;
}

void engine(const char **av, const char *buffer, char **map)
{
    int coords_saved[2] = {0, 0};
    int max_tokens = 0;
    int movements_left = 0;
    int tokens = 0;

    movements_left = get_movements(av);
    max_tokens = get_tokens(buffer);

    while (movements_left > 0 || tokens != max_tokens) {
        print_map(map, tokens, max_tokens, movements_left);
        get_next_point(map, coords_saved);
    }
    condition_win(map, tokens, max_tokens);
}
