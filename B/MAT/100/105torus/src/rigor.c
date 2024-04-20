/*
** EPITECH PROJECT, 2022
** rigor.c
** File description:
** rigor.c
*/

#include "../include/my.h"

int rules(void)
{
    printf("USAGE\n");
    printf("   ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n");
    printf("opt\tmethod option:\n");
    printf("\t\t1 for the bisection method\n");
    printf("\t\t2 for Newton's method\n");
    printf("\t\t3 for the secant method\n");
    printf("a[0-4]\tcoefficients of the equation\n");
    printf("n\tprecision (the application of the polynomial to the");
    printf("solution should be smaller than 10^⁻n)\n");
    return 0;
}

int rigor(int ac, const char **av)
{
    int it = 1;

    if (ac != 8) {
        return 84;
    }
    while (it < 8) {
        if (my_isnum(av[it]) != 0) {
            return 84;
        }
        it = it + 1;
    }
    if (atoi(av[1]) < 1 || atoi(av[1]) > 3 || atoi(av[7]) < 0) {
        return 84;
    }
    return 0;
}
