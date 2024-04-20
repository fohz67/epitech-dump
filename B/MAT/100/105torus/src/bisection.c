/*
** EPITECH PROJECT, 2022
** bisection.c
** File description:
** bisection.c
*/

#include "../include/my.h"

void display_bisection(struct st_torus *torus, double c, int i)
{
    if (i < torus->n) {
        printf("x = %.*f\n", i, c);
    } else {
        printf("x = %.*f\n", torus->n, c);
    }
}

int bisection(struct st_torus *torus)
{
    double a = 0;
    double b = 1;
    double c = 0;

    for (int i = 1; round(a * pow(10, torus->n) + 1) <
    round(b * pow(10, torus->n)); i++) {
        if (i > 500) {
            return 84;
        }
        display_bisection(torus, (c = (a + b) / 2), i);
        if (my_calc(torus, a) * my_calc(torus, c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    if (c < 0 || c > 1) {
        return 84;
    }
    return 0;
}
