/*
** EPITECH PROJECT, 2022
** engine.c
** File description:
** engine.c
*/

#include "my.h"

double engine(double n, double x)
{
    double res = 0;
    double res1 = 0;
    double res2 = 0;

    if (x == 0) {
        return 1;
    }
    for (double k = 0; k <= n; k++) {
        double temp = (2 * k) + 1;
        res1 = sin(x / temp);
        res2 = x / temp;
        if (k == 0) {
            res = res1 / res2;
        } else {
            res = res * res1 / res2;
        }
    }
    return res;
}
