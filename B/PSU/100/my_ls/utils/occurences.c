/*
** EPITECH PROJECT, 2022
** occurences.c
** File description:
** occurences.c
*/

#include "../include/my.h"

int occurences(int ac, const char **av, char *occurences)
{
    int index = 1;
    int count = 0;

    if (ac == 1) {
        return 0;
    }
    while (index < ac) {
        if (av[index][0] == '-') {
            occurences[0] = 'y';
        }
        if (av[index][0] != '-') {
            occurences[1] = 'y';
            count++;
        }
        if (count == 2) {
            occurences[2] = 'y';
        }
        index++;
    }
    return 0;
}
