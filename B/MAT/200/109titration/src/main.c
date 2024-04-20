/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int main(int ac, const char **av)
{
    titration titra;

    if (ac != 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], HELP_ARG) == 0) {
        write(1, HELP, my_strlen(HELP));
        return 0;
    }
    if (error(av[1]) == 84)
        return 84;
    if (open_file(av, &titra) == 84)
        return 84;
    if (check(&titra) == 84)
        return 84;
    engine(&titra);
    return 0;
}
