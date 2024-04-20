/*
** EPITECH PROJECT, 2023
** fractals_gest.c
** File description:
** fractals_gest.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"

int fractals_gestion(const char **av)
{
    int size = 0;
    char *first_pattern = NULL;
    char *second_pattern = NULL;

    size = my_getnbr(av[1]);
    first_pattern = my_strdup(av[2]);
    second_pattern = my_strdup(av[3]);

    if (first_pattern == NULL || second_pattern == NULL) {
        return 84;
    }
    if (size < 2) {
        basic_fractals(first_pattern, size);
    } else {
    }
    free(first_pattern);
    free(second_pattern);
    return 0;
}
