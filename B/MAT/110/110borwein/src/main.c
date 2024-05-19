/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int ac, const char **av)
{
    double nb = 0.0;

    if (ac != 2) {
        return 84;
    }
    if (ac == 2 && my_strcmp(av[1], HELP_ARG) == 0) {
        write(1, HELP, my_strlen(HELP));
        return 0;
    }
    if (is_digit(av[1]) == false) {
        return 84;
    }
    nb = atof(av[1]);
    midpoint(nb);
    trapezoidal(nb);
    simpson(nb);
    return 0;
}
