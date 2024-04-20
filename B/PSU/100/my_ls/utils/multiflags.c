/*
** EPITECH PROJECT, 2022
** flags.c
** File description:
** flags.c
*/

#include "../include/my.h"

void multiflags(const char **av, char *flag, int jindex)
{
    int index = 1;
    int length = 0;

    length = my_strlen(av[jindex]);

    while (index < length) {
        if (av[jindex][index] == 'a')
            flag[0] = 'y';
        if (av[jindex][index] == 'l')
            flag[1] = 'y';
        if (av[jindex][index] == 'R')
            flag[2] = 'y';
        if (av[jindex][index] == 'd')
            flag[3] = 'y';
        if (av[jindex][index] == 'r')
            flag[4] = 'y';
        if (av[jindex][index] == 't')
            flag[5] = 'y';
        index++;
    }
}
