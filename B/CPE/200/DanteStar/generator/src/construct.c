/*
** EPITECH PROJECT, 2022
** construct.c
** File description:
** construct.c
*/

#include <stdlib.h>
#include <string.h>
#include "generator.h"

int convert_maze(struct maze *mz)
{
    if ((mz->maze_buf = my_word_array_to_str(mz->maze)) == NULL) {
        return 84;
    }
    return 0;
}

void generate_maze(struct maze *mz)
{
    for (int i = 0; i < mz->height; i++) {
        for (int j = 0; j < mz->width; j++) {
            mz->maze[i][j] = 'X';
        }
    }
    mz->maze[0][0] = '*';
}

int allocate_maze(struct maze *mz)
{
    if ((mz->maze = malloc(sizeof(char *) * (mz->height + 1))) == NULL) {
        return 84;
    }
    for (int i = 0; i < mz->height; i++) {
        if ((mz->maze[i] = malloc(sizeof(char) * (mz->width + 1))) == NULL) {
            return 84;
        }
        mz->maze[i][mz->width] = '\0';
    }
    mz->maze[mz->height] = NULL;
    return 0;
}
