/*
** EPITECH PROJECT, 2022
** define.c
** File description:
** define.c
*/

#include "./include/my.h"

void define_struct(const char **av, struct utils *utils)
{
    utils->x = atof(av[2]);
    utils->y = atof(av[3]);
    utils->z = atof(av[4]);
    utils->Vx = atof(av[5]);
    utils->Vy = atof(av[6]);
    utils->Vz = atof(av[7]);
    utils->spec = atof(av[8]);

}
