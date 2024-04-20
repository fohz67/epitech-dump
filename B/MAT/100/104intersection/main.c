/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

int main(int ac, const char **av)
{
    struct utils utils;
    struct cal cal;

    if (ac == 2 && my_strcmp(av[1], HELP_ARG) == 0) {
        write(1, HELP, my_strlen(HELP));
        return SUCCESS;
    }
    if (check_args(ac, av) == ERROR) {
        return ERROR;
    }

    define_struct(av, &utils);
    show_type(av, &utils, &cal);
    return SUCCESS;
}
