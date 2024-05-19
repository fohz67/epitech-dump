/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

void growth_rate(const char **av)
{
    int i = 1;
    double x0 = atof(av[1]);
    double k = atof(av[2]);
    double x1 = 0;

    while (i <= 100) {
        printf("%d %.2f\n", i, x0);
        x1 = x0 * k * ((1000 - x0) / 1000);
        x0 = x1;
        i++;
    }
}

void generation_bis(const char **av, double k)
{
    int i = 1;
    double x0 = atof(av[1]);
    double i0 = atof(av[2]);
    double i1 = atof(av[3]);

    while (i <= i1) {
        while (i < i0) {
            x0 = k * x0 * ((1000 - x0) / 1000);
            i++;
        }
        x0 = k * x0 * ((1000 - x0) / 1000);
        printf("%.2f %.2f\n", k, x0);
        i++;
    }
}

void generation(const char **av)
{
    double k = 1;

    while (k <= 4.00) {
        generation_bis(av, k);
        k += 0.01;
    }
}

int main(int ac, const char *av[])
{
    if (ac == 2 && strcmp(av[1], HELP_ARG) == 0) {
        write(1, HELP, strlen(HELP));
        return 0;
    }
    if ((ac != 3 && ac != 4) || check_args(ac, av) == 84) {
        return 84;
    }
    if (ac == 3) {
        growth_rate(av);
    }
    if (ac == 4) {
        generation(av);
    }
    return 0;
}
