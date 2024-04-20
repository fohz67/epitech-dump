/*
** EPITECH PROJECT, 2022
** newton.c
** File description:
** newton.c
*/

#include "../include/my.h"

int newton(struct st_torus *torus)
{
    double x = 0.5;

    printf("x = 0.5\n");
    for (int i = 1; my_abs(my_calc(torus, x)) > 1 / pow(10, torus->n); i++) {
        if (i > 500 || my_deriv(torus, x) == 0) {
            return 84;
        }
        x = x - my_calc(torus, x) / my_deriv(torus, x);
        printf("x = %.*f\n", torus->n, x);
    }
    if (x < 0 || x > 1) {
        return 84;
    }
    return 0;
}
