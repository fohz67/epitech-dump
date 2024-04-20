/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "architect.h"

int checker_tz(const char **av, const char *ch)
{
    if (ch[1] == 't') {
        printf("Translation along vector (%d, %d)\n",
        atoi(av[4]), atoi(av[5]));
        printf("1.00\t0.00\t%.2f\n", atof(av[4]));
        printf("0.00\t1.00\t%.2f\n", atof(av[5]));
        printf("0.00\t0.00\t1.00");
        printf("\n(%.2f, %.2f) => ", atof(av[1]), atof(av[2]));
        printf("(%.2f, %.2f)\n", atof(av[1]) + atof(av[4]),
        atof(av[2]) + atof(av[5]));
    }
    if (ch[1] == 'z') {
        printf("Scaling by factors %d and %d\n", atoi(av[4]), atoi(av[5]));
        printf("%.2f\t0.00\t0.00\n", atof(av[4]));
        printf("0.00\t%.2f\t0.00\n", atof(av[5]));
        printf("0.00\t0.00\t1.00");
        printf("\n(%.2f, %.2f) => ", atof(av[1]), atof(av[2]));
        printf("(%.2f, %.2f)\n", atof(av[1]) * atof(av[4]),
        atof(av[2]) * atof(av[5]));
    }
    return 0;
}

int checker_sr(const char **av, const char *ch)
{
    float cc = cos(atof(av[4]) / 180 * M_PI);
    float ss = sin(atof(av[4]) / 180 * M_PI);
    double cc1 = cos(2 * (float) (atof(av[4]) / 180 * M_PI));
    double ss1 = sin(2 * (float) (atof(av[4]) / 180 * M_PI));
    if (ch[1] == 's') {
        printf("Reflection over an axis with an inclination angle of %d \
degrees\n", atoi(av[4]));
        printf("%.2f\t%.2f\t0.00\n%.2f\t%.2f\t0.00\n", cc1, ss1, ss1, -cc1);
        printf("0.00\t0.00\t1.00\n(%.2f, %.2f) ", atof(av[1]), atof(av[2]));
        printf("=> (%.2f, %.2f)\n", cc1 * atof(av[1]) +  -ss1 * atof(av[2]),
        ss1 * atof(av[1]) + cc1 * atof(av[2]));
    }
    if (ch[1] == 'r') {
        printf("Rotation by a %d degree angle\n", atoi(av[4]));
        printf("%.2f\t%.2f\t0.00\n%.2f\t%.2f\t0.00\n", cc, -ss, ss, cc);
        printf("0.00\t0.00\t1.00\n(%.2f, %.2f) ", atof(av[1]), atof(av[2]));
        printf("=> (%.2f, %.2f)\n", cc * atof(av[1]) + -ss * atof(av[2]),
        ss * atof(av[1]) + cc * atof(av[2]));
    }
    return 0;
}

int errors2(const char **av, int index)
{
    int c = 0;

    while (av[index][c] != '\0') {
        char ch = av[index][c];
        if (!((ch >= '0' && ch <= '9') || (ch == '.' || ch == '-'))) {
            return 84;
        }
        c++;
    }
    return 0;
}

int errors(const char **av, int maxi)
{
    int index = 1;

    while (index < maxi) {
        if (index == 3) {
            index++;
        }
        if (errors2(av, index) == 84) {
            return 84;
        }
        index++;
    }
    return 0;
}

int main(int ac, const char **av)
{
    int maxi = 0;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write(1, HELP, strlen(HELP));
        return 0;
    }
    if (ac < 5)
        return 84;
    if (strcmp(av[3], "-t") == 0 || strcmp(av[3], "-z") == 0)
        maxi = 6;
    if (strcmp(av[3], "-r") == 0 || strcmp(av[3], "-s") == 0)
        maxi = 5;
    if (ac != maxi || errors(av, maxi) == 84)
        return 84;
    if (maxi == 5)
        return checker_sr(av, av[3]);
    if (maxi == 6)
        return checker_tz(av, av[3]);
    return 0;
}
