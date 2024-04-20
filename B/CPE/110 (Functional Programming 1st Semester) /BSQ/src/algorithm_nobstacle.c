/*
** EPITECH PROJECT, 2022
** algorithm_nobstacle.c
** File description:
** algorithm_nobstacle.c
*/

#include "../include/my.h"

int algorithm_nobstacle(char **tab, char *buffer, int size)
{
    int x = my_nbline(buffer);
    int y = 0;
    int max = 0;

    while (tab[1][y] != ENDSTR)
            y = y + 1;
    if (x >= y)
        max = y;
    if (y > x)
        max = x;
    return convert(tab, max, 1, 0)
    + show(tab, size, my_nbrlen(my_nbline(buffer)));
}
