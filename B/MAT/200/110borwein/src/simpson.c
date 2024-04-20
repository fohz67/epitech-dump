/*
** EPITECH PROJECT, 2022
** simpson.c
** File description:
** simpson.c
*/

#include "my.h"

void simpson(double n)
{
    double pi = M_PI / 2;
    double res = 0;

    for (double a = 0, b = 0.5; b <= 5000; a += 0.5, b += 0.5) {
        double temp = engine(n, a) + engine(n, b);
        temp += 4 * engine(n, ((a + b) / 2));
        temp *= ((b - a) / 6);
        res += temp;
    }
    double new_pi = fabs(res - pi);
    printf("Simpson:\nI%.0f = %.10f\n", n, res);
    printf("diff = %.10f\n", new_pi);
}
