/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init.c
*/

#include "../include/my.h"

int init_game(int ac, const char **av, struct sigaction *sig)
{
    my_game.win = 0;
    if (ac == 2 && first_id(sig) == 84) {
        return 84;
    }
    if (ac == 3 && second_id(sig, av) == 84) {
        return 84;
    }
    return 0;
}
