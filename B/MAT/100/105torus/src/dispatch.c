/*
** EPITECH PROJECT, 2022
** dispatch.c
** File description:
** dispatch.c
*/

#include "../include/my.h"

int dispatch(struct st_torus *torus)
{
    if (torus->opt == 1) {
        return bisection(torus);
    }
    if (torus->opt == 2) {
        return newton(torus);
    }
    if (torus->opt == 3) {
        return secant(torus);
    }
    return 84;
}
