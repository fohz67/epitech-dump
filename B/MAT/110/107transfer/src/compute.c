/*
** EPITECH PROJECT, 2020
** transfer
** File description:
** compute
*/

#include <stdio.h>
#include "transfer.h"

double compute_result(transfer *tr, double x)
{
    double n = tr->tab_a[tr->max_a - 1];
    double res_a = 0;

    for (int i = (tr->max_a - 2); i >= 0; i--) {
        res_a = (n * x) + tr->tab_a[i];
        n = res_a;
    }

    double n_b = tr->tab_b[tr->max_b];
    double res_b = 0;

    for (int i = (tr->max_b - 1); i >= 0; i--) {
        res_b = (n_b * x) + tr->tab_b[i];
        n_b = res_b;
    }
    return res_a / res_b;
}

static void compute_hard(transfer *tr, const char **av, int ac)
{
    int nb = (ac - 1) / 2;

    for (double x = 0; x <= 1.001; x += 0.001) {
        tr = struct1(tr, av);
        double res = compute_result(tr, x);
        for (int i = 1; i < nb; i++) {
            tr = struct2(tr, av[2 * i + 1], av[2 * i + 2]);
            res *= compute_result(tr, x);
        }
        printf("%.3f -> %.5f\n", x, res);
    }
}

void compute_simple(transfer *tr)
{
    for (double x = 0; x <= 1.001; x += 0.001) {
        double res_a = tr->tab_a[tr->max_a - 1];
        double res_b = tr->tab_b[tr->max_b];
        for (int i = tr->max_a - 2; i >= 0; i--) {
            res_a = (res_a * x) + tr->tab_a[i];
        }
        for (int i = tr->max_b - 1; i >= 0; i--) {
            res_b = (res_b * x) + tr->tab_b[i];
        }
        double res = res_a / res_b;
        printf("%.3f -> %.5f\n", x, res);
    }
}

void compute(transfer *tr, int ac, const char **av)
{
    if (ac == 3) {
        compute_simple(tr);
    } else {
        compute_hard(tr, av, ac);
    }
}
