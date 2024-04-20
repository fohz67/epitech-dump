/*
** EPITECH PROJECT, 2022
** generator.c
** File description:
** generator.c
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"

void generate_paths(struct maze *mz, int x, int y, int z)
{
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    if (z > 72000) exit(0);
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4, temp_x = dir[i][0], temp_y = dir[i][1];
        dir[i][0] = dir[j][0];
        dir[i][1] = dir[j][1];
        dir[j][0] = temp_x;
        dir[j][1] = temp_y;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0] * 2;
        int ny = y + dir[i][1] * 2;
        if (nx < 0 || ny < 0 || nx >= mz->height || ny >= mz->width) continue;
        if (mz->maze[nx][ny] == 'X') {
            mz->maze[nx][ny] = '*';
            mz->maze[x + dir[i][0]][y + dir[i][1]] = '*'; z += 1;
            generate_paths(mz, nx, ny, z++);
        }
    }
}

void generate_walls(struct maze *mz, int ac)
{
    if ((mz->width % 2 == 0 || mz->height % 2 == 0) && ac == 4) {
        mz->maze[mz->height - 1][mz->width - 2] = '*';
    } else if (ac == 3) {
        mz->maze[mz->height - 1][mz->width - 2] = '*';
        mz->maze[mz->height - 2][mz->width - 1] = '*';
    }
    mz->maze[mz->height - 1][mz->width - 1] = '*';
}
