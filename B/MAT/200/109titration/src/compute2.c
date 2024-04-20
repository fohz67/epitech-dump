/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** compute2.c
*/

#include <stdlib.h>
#include "my.h"

static double compute_forward_bis(titration *titra, int i)
{
    double res = 0;

    titra->h = (titra->tabx[i + 1] - titra->tabx[i]);
    res = (titra->dev[i + 1] - titra->dev[i]) / titra->h;
    return (res);
}

static double compute_backward_bis(titration *titra, int i)
{
    double res = 0;

    titra->hprime = (titra->tabx[i] - titra->tabx[i - 1]);
    res = (titra->dev[i] - titra->dev[i - 1]) / titra->hprime;
    return (res);
}

void cmp_deriv2(titration *titra)
{
    double stk = 0;
    double stk1 = 0;

    for (int i = 2; i != titra->nb - 2; i++) {
        stk = compute_forward_bis(titra, i);
        stk1 = compute_backward_bis(titra, i);
        titra->sec[i] = ((stk * titra->hprime) + (stk1 * titra->h)) /
        (titra->h + titra->hprime);
    }
}
