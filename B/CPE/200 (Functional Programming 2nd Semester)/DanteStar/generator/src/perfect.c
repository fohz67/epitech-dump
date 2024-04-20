/*
** EPITECH PROJECT, 2022
** perfect.c
** File description:
** perfect.c
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "generator.h"

int perfect(const char **av, int ac)
{
    int result = 0;
    struct maze mz = {NULL, NULL, NULL, atoi(av[1]), atoi(av[2])};

    srand(time(NULL));

    if (allocate_maze(&mz) == 84) {
        result = 84;
    } else {
        generate_maze(&mz);
        generate_paths(&mz, 0, 0, 0);
        generate_walls(&mz, ac);
        if (convert_maze(&mz) == 84) {
            result = 84;
        } else {
            write(1, mz.maze_buf, my_strlen(mz.maze_buf));
            result = 0;
        }
        free_all(&mz, result);
    }
    return result;
}
