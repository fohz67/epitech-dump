/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** compute.c
*/

#include <stdlib.h>
#include "my.h"

static double cmp_top(titration *titra, int i)
{
    double res = 0;

    double h = titra->tabx[i + 1] - titra->tabx[i];
    if (h == 0) {
        exit(84);
    }
    res = (titra->taby[i + 1] - titra->taby[i]) / h;
    return res;
}

static double cmp_bot(titration *titra, int i)
{
    double res = 0;

    double hprime = titra->tabx[i] - titra->tabx[i - 1];
    if (hprime == 0) {
        exit(84);
    }
    res = (titra->taby[i] - titra->taby[i - 1]) / hprime;
    return res;
}

void cmp_deriv(titration *titra)
{
    double stk = 0;
    double stk1 = 0;

    for (int i = 1; i < titra->nb - 1; i++) {
        stk = cmp_top(titra, i);
        stk1 = cmp_bot(titra, i);
        double h = titra->tabx[i + 1] - titra->tabx[i - 1];
        if (h == 0) {
            exit(84);
        }
        titra->dev[i] = ((stk * (titra->tabx[i] - titra->tabx[i - 1])) +
        (stk1 * (titra->tabx[i + 1] - titra->tabx[i]))) / h;
    }
}
