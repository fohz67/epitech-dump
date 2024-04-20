/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "../include/my.h"
game my_game;

int main(int ac, const char **av)
{
    struct sigaction sig;

    if (ac == 2 && my_strcmp(av[1], HELP_ARG) == 0) {
        write(1, HELP, my_strlen(HELP));
        return 0;
    }
    if (file_maps(ac, av) == 84) {
        return 84;
    }
    if (check_errors(ac) == 84) {
        return 84;
    }
    base_id(&sig);
    if (init_game(ac, av, &sig) == 84) {
        return 84;
    }
    return 0;
}
