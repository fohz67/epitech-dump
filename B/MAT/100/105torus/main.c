/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

int main(int ac, const char** av)
{
    struct st_torus torus;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        return rules();
    }
    if (rigor(ac, av) == 84) {
        return 84;
    }
    init_structure(av, &torus);
    return dispatch(&torus);
}
