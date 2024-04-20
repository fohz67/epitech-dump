/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "generator.h"

static void dispatcher(int ac, const char **av)
{
    if (ac == 3) {
        imperfect(av, ac);
    }
    if (ac == 4) {
        perfect(av, ac);
    }
}

int main(int ac, const char **av)
{
    if (ac != 3 && ac != 4) {
        return 84;
    }
    if (error(ac, av) == 84) {
        return 84;
    }
    dispatcher(ac, av);
    return 0;
}
