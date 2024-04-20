/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main.c
*/

#include "lib.h"
#include "corewar.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        help();
    }
    return (0);
}
