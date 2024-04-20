/*
** EPITECH PROJECT, 2022
** imperfect.c
** File description:
** imperfect.c
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "generator.h"

static int remove_walls(struct maze *mz)
{
    int i = 0;
    int diff = 0;

    diff = (mz->height + mz->width) / 4;
    if ((mz->maze_buf = my_word_array_to_str(mz->maze)) == NULL) {
        return 84;
    }
    while (mz->maze_buf[i] != '\0') {
        if (mz->maze_buf[i] == 'X' && rand() % diff == 1) {
            mz->maze_buf[i] = '*';
        }
        i++;
    }
    return 0;
}

int imperfect(const char **av, int ac)
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
        if (remove_walls(&mz) == 84) {
            result = 84;
        } else {
            write(1, mz.maze_buf, my_strlen(mz.maze_buf));
            result = 0;
        }
        free_all(&mz, result);
    }
    return result;
}
