/*
** EPITECH PROJECT, 2022
** squaring.c
** File description:
** squaring.c
*/

#include "../include/my.h"

int square_land(char **tab, int x, int y, int m_y)
{
    while (y < m_y) {
        if (tab[x][y] == WATER) {
            y = y + 1;
        } else {
            return NO_VALUE;
        }
    }
    return BASIC;
}

int square(char **tab, int x, int y, int count)
{
    int m_x = x + count;
    int m_y = y + count;
    int s_y = y;

    while (x < m_x) {
        if (square_land(tab, x, y, m_y) == 0) {
            return NO_VALUE;
        }
        y = s_y;
        x = x + 1;
    }
    return count;
}
