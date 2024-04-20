/*
** EPITECH PROJECT, 2022
** library.c
** File description:
** library.c
*/

#include "../include/my.h"

double my_deriv(struct st_torus *torus, double x)
{
    double result = 0;

    result = torus->a4 * 4 * x * x * x;
    result = result + torus->a3 * 3 * x * x;
    result = result + torus->a2 * 2 * x;
    result = result + torus->a1 * 1;
    result = result + torus->a0 * 0;
    return result;
}

double my_calc(struct st_torus *torus, double x)
{
    double result = 0;

    result = torus->a4 * x * x * x * x;
    result = result + torus->a3 * x * x * x;
    result = result + torus->a2 * x * x;
    result = result + torus->a1 * x;
    result = result + torus->a0;
    return result;
}

double my_abs(double nb)
{
    if (nb < 0) {
        nb = nb * -1;
    }
    return nb;
}

int my_isnum(const char *str)
{
    int index = 0;

    if (str[index] == '-') {
        index = index + 1;
    }
    while (str[index] != '\0') {
        if (str[index] < '0' || str[index] > '9') {
            return 84;
        }
        index = index + 1;
    }
    return 0;
}
