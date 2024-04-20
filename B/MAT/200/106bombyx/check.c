/*
** EPITECH PROJECT, 2022
** check.c
** File description:
** check.c
*/

#include "./include/my.h"

int isnbr_dec(const char *str)
{
    size_t i = 0;

    while (i < strlen(str)) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
            return 84;
        }
        i++;
    }
    return 0;
}

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

int check_args(int ac, const char **av)
{
    if (atof(av[1]) <= 0)
        return 84;
    if (ac == 3) {
        if (isnbr(av[1]) == 84 ||
            isnbr_dec(av[2]) == 84 ||
            atof(av[2]) < 1 ||
            atof(av[2]) > 4) {
            return 84;
        }
    }
    if (ac == 4) {
        if (isnbr(av[1]) == 84 ||
            isnbr(av[2]) == 84 ||
            isnbr(av[3]) == 84 ||
            atof(av[1]) <= 0 ||
            atof(av[1]) >= atof(av[2])) {
        return 84;
        }
    }
    return 0;
}
