/*
** EPITECH PROJECT, 2022
** trapezoidal.c
** File description:
** trapezoidal.c
*/

#include "my.h"

void trapezoidal(double n)
{
    double pi = M_PI / 2;
    double res = 0;

    for (double a = 0, b = 0.5; b <= 5000; a += 0.5, b += 0.5) {
        double temp = engine(n, a) + engine(n, b);
        temp *= ((b - a) / 2);
        res += temp;
    }
    double new_pi = fabs(res - pi);
    printf("Trapezoidal:\nI%.0f = %.10f\n", n, res);
    printf("diff = %.10f\n\n", new_pi);
}
