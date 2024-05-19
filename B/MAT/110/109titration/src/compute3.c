/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** compute3.c
*/

#include <stdlib.h>
#include "my.h"

static char **my_split_alloc(char *src, char **str, int nb)
{
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == ';' || src[i] == '\n') {
            str[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        }
    }
    str[nb] = malloc(sizeof(char) * 1);
    return (str);
}

char **my_split(char *src, int nb)
{
    char **str = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int m = 0;
    int k = 0;

    str = my_split_alloc(src, str, nb);
    for (int j = 0; src[j] != '\0'; m++, j++);
    m++;
    for (int j = 0; i != m; i++, k++) {
        if (src[i] == ';' || src[i] == '\n') {
            str[j][k] = '\0';
            j++;
            i++;
            k = 0;
        }
        str[j][k] = src[i];
    }
    free(str[nb]);
    str[nb] = NULL;
    return (str);
}

static void compute_after(titration *titra, int i)
{
    double b = 0;
    double a = 0;

    for (double x = titra->eq_p; x <= titra->tabx[i + 1];
    x += 0.1, titra->j += 1) {
        titra->f[titra->j] = x;
        titra->j += 1;
        b = (titra->tabx[i] * titra->sec[i + 1]) -
        (titra->tabx[i + 1] * titra->sec[i]);
        b = b / (titra->tabx[i] - titra->tabx[i + 1]);
        a = (titra->sec[i] - titra->sec[i + 1]) /
        (titra->tabx[i] - titra->tabx[i + 1]);
        a = a * x;
        titra->f[titra->j] = a + b;
    }
}

static void compute_before(titration *titra, int i)
{
    double b = 0;
    double a = 0;

    for (double x = titra->tabx[i - 1]; x <= titra->eq_p;
    x += 0.1, titra->j += 1) {
        titra->f[titra->j] = x;
        titra->j += 1;
        b = (titra->tabx[i - 1] * titra->sec[i]) - (titra->tabx[i] *
        titra->sec[i - 1]);
        b = b / (titra->tabx[i - 1] - titra->tabx[i]);
        a = (titra->sec[i - 1] - titra->sec[i]) / (titra->tabx[i - 1] -
        titra->tabx[i]);
        a = a * x;
        titra->f[titra->j] = a + b;
    }
}

void cmp_estim(titration *titra)
{
    int i = 2;
    double k = 0;

    for (; titra->eq_p != titra->tabx[i]; i++);
    k = (((titra->tabx[i + 1] - titra->tabx[i - 1]) * 10) + 1) * 2;
    titra->f = malloc(sizeof(double) * k);
    titra->j = 0;
    compute_before(titra, i);
    titra->eq_p += 0.1;
    compute_after(titra, i);
}
