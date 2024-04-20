/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error.c
*/

#include "lib.h"
#include "corewar.h"

int check_hexa(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'F') ||
        (str[i] >= '0' && str[i] <= '9'))) {
            return 84;
        }
    }
    return 0;
}

int error(char **av)
{
    char *str = av[2];

    if (my_strcmp(av[1], "-dump") == 0) {
        if (check_hexa(str) == 84) {
            return 84;
        }
    }
    return 0;
}
