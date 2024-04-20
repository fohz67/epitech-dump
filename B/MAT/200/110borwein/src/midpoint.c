/*
** EPITECH PROJECT, 2022
** midpoint.c
** File description:
** midpoint.c
*/

#include "my.h"

void midpoint(double n)
{
    double pi = M_PI / 2;
    double res = 0;

    for (double a = 0, b = 0.5; b <= 5000; a += 0.5, b += 0.5) {
        double res1 = engine(n, ((a + b) / 2));
        res1 *= b - a;
        res += res1;
    }
    double new_pi = fabs(res - pi);
    printf("Midpoint:\nI%.0f = %.10f\n", n, res);
    printf("diff = %.10f\n\n", new_pi);
}
