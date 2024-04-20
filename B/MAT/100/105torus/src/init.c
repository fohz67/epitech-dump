/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init.c
*/

#include "../include/my.h"

void init_structure(const char **av, struct st_torus *torus)
{
    torus->opt = atoi(av[1]);
    torus->a0 = atoi(av[2]);
    torus->a1 = atoi(av[3]);
    torus->a2 = atoi(av[4]);
    torus->a3 = atoi(av[5]);
    torus->a4 = atoi(av[6]);
    torus->n = atoi(av[7]);
}
