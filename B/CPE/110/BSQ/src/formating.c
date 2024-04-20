/*
** EPITECH PROJECT, 2022
** formating.c
** File description:
** formating.c
*/

#include "../include/my.h"

int show(char **tab, int size, int remove)
{
    int x = 1;
    int y = 0;
    int index = 0;
    char *new_buffer = malloc (sizeof(char) * (size + 1));

    while (my_strcmp(tab[x], END) != 0) {
        while (tab[x][y] != ENDSTR) {
            new_buffer[index] = tab[x][y];
            index = index + 1;
            y = y + 1;
        }
        new_buffer[index] = '\n';
        index = index + 1;
        x = x + 1;
        y = 0;
    }
    write(1, new_buffer, size - remove - 1);
    return SUCCESS;
}

int convert(char **tab, int best, int b_x, int b_y)
{
    int sb_x = b_x + best;
    int sb_y = b_y + best;

    while (b_x < sb_x) {
        while (b_y < sb_y) {
            tab[b_x][b_y] = LAND;
            b_y = b_y + 1;
        }
        b_y = b_y - best;
        b_x = b_x + 1;
    }
    return SUCCESS;
}
