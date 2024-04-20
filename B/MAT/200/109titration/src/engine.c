/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** engine.c
*/

#include "my.h"

static void search_value_around_zero(titration *titra)
{
    for (int i = 1; i <= titra->j; i += 2) {
        if (titra->f[i] < 0) {
            titra->f[i] *= -1;
        }
    }
    titra->eq_p = titra->f[1];
    for (int i = 1; i <= titra->j - 2; i += 2) {
        if (titra->f[i] > titra->f[i + 2]) {
            titra->eq_p = titra->f[i + 1];
        }
    }
}

static void find_eq_point(titration *titra)
{
    titra->eq_p = titra->tabx[1];
    for (int i = 0; i != titra->nb - 1; i++) {
        if (titra->dev[i] < titra->dev[i + 1]) {
            titra->eq_p = titra->tabx[i + 1];
        }
    }
}

void engine(titration *titra)
{
    cmp_deriv(titra);
    display_deriv(titra);
    find_eq_point(titra);
    display_equivalence(titra);
    cmp_deriv2(titra);
    display_second_deriv(titra);
    cmp_estim(titra);
    display_second_deriv_esti(titra);
    search_value_around_zero(titra);
    display_equivalence(titra);
}
