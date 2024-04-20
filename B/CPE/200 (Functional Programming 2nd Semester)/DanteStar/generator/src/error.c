/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error.c
*/

#include <stdlib.h>
#include <string.h>
#include "generator.h"

int isnbr(const char *str)
{
    size_t i = 0;

    while (i < strlen(str)) {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
        i++;
    }
    return 0;
}

int error(int ac, const char **av)
{
    if (isnbr(av[1]) == 84) {
        return 84;
    }
    if (isnbr(av[2]) == 84) {
        return 84;
    }
    if (atoi(av[1]) <= 1 || atoi(av[2]) <= 1) {
        return 84;
    }
    if (ac == 4 && strcmp("perfect", av[3]) != 0) {
        return 84;
    }
    return 0;
}
