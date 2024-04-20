/*
** EPITECH PROJECT, 2022
** check.c
** File description:
** check.c
*/

#include "./include/my.h"

int check_args(int ac, const char **av)
{
    int index = 1;

    if (ac != 9)
        return ERROR;
    if (my_strlen(av[1]) != 1 || atof(av[1]) < 1 || atof(av[1]) > 3)
        return ERROR;
    while (av[index] != NULL) {
        if (my_isnum(av[index]) != 0) {
            return ERROR;
        }
        index = index + 1;
    }
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && atof(av[7]) == 0)
        return ERROR;
    if (atof(av[1]) == 3 && atof(av[8]) > 360)
        return ERROR;
    if ((atof(av[1]) == 3 && my_getnbr(av[8]) < 0) ||
    (atof(av[1]) != 3 && my_getnbr(av[8]) <= 0))
        return ERROR;
    return SUCCESS;
}
