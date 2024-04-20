/*
** EPITECH PROJECT, 2022
** algorithm.c
** File description:
** algorithm.c
*/

#include "../include/my.h"

int one(char *buffer, int remove)
{
    int index = remove + 1;
    int already = 0;

    while (buffer[index] != ENDSTR) {
        if (buffer[index] == WATER && already == 0) {
            buffer[index] = LAND;
            already = 1;
        }
        my_putchar(buffer[index]);
        index = index + 1;
    }
    return SUCCESS;
}

int loop(char **tab, struct square *b, int x, int y)
{
    if (tab[x][y] == OBSTACLE) {
        b->count = 0;
        return NO_VALUE;
    }

    b->loop = b->count;
    while (b->loop >= 0) {
        b->new = square(tab, x, y - b->loop, b->loop + 1);
        if (b->best < b->new) {
            b->best = b->new;
            b->best_x = x;
            b->best_y = y - b->loop;
        }
        b->loop--;
    }
    b->count++;
    return SUCCESS;
}

int algorithm(char **tab, char *buffer, int size, struct square b)
{
    int x = 1;
    int y = 0;
    int nbcheck = my_nbcheck(tab);

    if (nbcheck > 0)
        return one(buffer, my_nbrlen(my_nbline(buffer)));
    while (my_strcmp(tab[x], END) != 0) {
        while (tab[x][y] != ENDSTR) {
            loop(tab, &b, x, y);
            y++;
        }
        y = 0;
        x++;
    }
    return convert(tab, b.best, b.best_x, b.best_y)
    + show(tab, size, my_nbrlen(my_nbline(buffer)));
}
