/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error.c
*/

#include <stdlib.h>
#include "generator.h"

void free_all(struct maze *mz, int result)
{
    int i = 0;

    if (result == 0) {
        free(mz->maze_buf);
    }
    while (mz->maze[i] && mz->maze[i] != NULL) {
        free(mz->maze[i]);
        i++;
    }
}
