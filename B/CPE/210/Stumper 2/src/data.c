/*
** EPITECH PROJECT, 2023
** data.c
** File description:
** data.c
*/

#include <stdlib.h>

int get_tokens(const char *buffer)
{
    int i = 0;
    int tokens = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'T') {
            tokens++;
        }
        i++;
    }
    return tokens;
}

int get_movements(const char **av)
{
    int movements = 0;

    if (av[1][1] == 'm') {
        movements = atoi(av[2]);
    }
    if (av[3][1] == 'm') {
        movements = atoi(av[4]);
    }
    return movements;
}
