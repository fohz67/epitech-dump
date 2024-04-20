/*
** EPITECH PROJECT, 2022
** secant.c
** File description:
** secant.c
*/

#include "../include/my.h"

void display_secant(struct st_torus *torus, double c, int i)
{
    if (i == 0) {
        printf("x = 0.5\n");
    } else {
        printf("x = %.*f\n", torus->n, c);
    }
}

int secant(struct st_torus *torus)
{
    double a = 0;
    double b = 1;
    double c = 0;

    for (int i = 0; my_abs(my_calc(torus, c)) > 1 / pow(10, torus->n); i++) {
        if (i > 500 || my_calc(torus, b) - my_calc(torus, a) == 0) {
            return 84;
        }
        c = b - ((my_calc(torus, b) * (b - a)) /
        (my_calc(torus, b) - my_calc(torus, a)));
        display_secant(torus, c, i);
        a = b;
        b = c;
    }
    if (c < 0 || c > 1) {
        return 84;
    }
    return 0;
}
