/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** display.c
*/

#include <stdio.h>
#include "my.h"

void display_deriv(titration *titra)
{
    printf("Derivative:\n");
    for (int i = 1; i != titra->nb - 1; i++)
        printf("%.1f ml -> %.2f\n", titra->tabx[i], titra->dev[i]);
    printf("\n");
}

void display_second_deriv(titration *titra)
{
    printf("\nSecond derivative:\n");
    for (int i = 2; i != titra->nb - 2; i++)
        printf("%.1f ml -> %.2f\n", titra->tabx[i], titra->sec[i]);
    printf("\n");
}

void display_second_deriv_esti(titration *titra)
{
    printf("Second derivative estimated:\n");
    for (int i = 1; i <= titra->j; i += 2)
        printf("%.1f ml -> %.2f\n", titra->f[i - 1], titra->f[i]);
    printf("\n");
}

void display_equivalence(titration *titra)
{
    printf("Equivalence point at %.1f ml\n", titra->eq_p);
}
