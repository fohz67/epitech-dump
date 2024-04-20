/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display.c
*/

#include "../include/my.h"

int display(char **tab, const char *path, char *flag, int size)
{
    int index = 0;
    int blk = 0;

    my_sort_ascii(size, tab);
    if (flag[5] == 'y')
        my_sort_time(size, tab, path);
    if (flag[1] == 'y' && flag[3] == 'n') {
        while (index < size)
            blk = blk + blksize(tab, path, index++);
        my_putstr("total ") + my_putlong(blk) + my_putchar('\n');
    }
    index = 0;
    if (flag[4] == 'y') {
        index = size - 1;
        while (index >= 0)
            show(tab, path, index--, flag);
    } else
        while (index < size)
            show(tab, path, index++, flag);
    return 0;
}
