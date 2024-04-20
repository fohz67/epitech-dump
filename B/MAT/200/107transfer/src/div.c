/*
** EPITECH PROJECT, 2020
** transfer
** File description:
** check_div
*/

#include <stdlib.h>
#include "transfer.h"

static double div_result(transfer *tr, double x)
{
    double n = tr->tab_a[tr->max_a - 1];
    double res_a = 0;
    double res_b = 0;

    for (int i = (tr->max_a - 2); i >= 0; i--) {
        res_a = (n * x) + tr->tab_a[i];
        n = res_a;
    }
    n = tr->tab_b[tr->max_b];
    for (int i = (tr->max_b - 1); i >= 0; i--) {
        res_b = (n * x) + tr->tab_b[i];
        n = res_b;
    }
    if (res_b == 0)
        exit(84);
    return res_a / res_b;
}

static void div_hard(transfer *tr, const char **av, int ac)
{
    int nb = (ac - 1) / 2;
    double res = 0;

    for (double x = 0; x <= 1.001; x += 0.001) {
        tr = struct1(tr, av);
        res = div_result(tr, x);
        for (int i = 1, j = 3; i != nb; i++, j += 2) {
            tr = struct2(tr, av[j], av[j + 1]);
            div_result(tr, x);
            res *= div_result(tr, x);
        }
    }
}

static void div_simple(transfer *tr)
{
    double n = 0;

    for (double x = 0; x <= 1.001; x += 0.001) {
        n = tr->tab_a[tr->max_a - 1];
        for (int i = (tr->max_a - 2); i != -1; i--) {
            tr->res_a = (n * x) + tr->tab_a[i];
            n = tr->res_a;
        }
        n = tr->tab_b[tr->max_b];
        for (int i = (tr->max_b - 1); i != -1; i--) {
            tr->res_b = (n * x) + tr->tab_b[i];
            n = tr->res_b;
        }
        if (tr->res_b == 0) {
            exit(84);
        }
    }
}

void divi(transfer *tr, int ac, const char **av)
{
    if (ac == 3) {
        div_simple(tr);
    } else {
        div_hard(tr, av, ac);
    }
}
