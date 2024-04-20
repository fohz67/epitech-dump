/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int ac, const char **av)
{
    if (error_gestion(ac, av) == 84) {
        return 84;
    } else if (fractals_gestion(av) == 84) {
        return 84;
    }
    return 0;
}
