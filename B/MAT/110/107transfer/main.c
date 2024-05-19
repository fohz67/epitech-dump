/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "transfer.h"

static int check2(const char **av, int i)
{
    int j = 0;

    while (av[i][j] != '\0') {
        if (av[i][j] == '*' || av[i][j] == '-') {
            j++;
            continue;
        }
        if (av[i][j] < '0' || av[i][j] > '9') {
            return 84;
        }
        j++;
    }
    return 0;
}

int check(int ac, const char **av)
{
    int i = 1;

    while (i < ac) {
        if (check2(av, i) == 84) {
            return 84;
        }
        i++;
    }
    return 0;
}

static int error(int ac, const char **av)
{
    if (ac < 3) {
        return 84;
    }
    if (ac % 2 != 1) {
        return 84;
    }
    if (check(ac, av) == 84) {
        return 84;
    }
    return 0;
}

int main(int ac, const char **av)
{
    transfer *tr = NULL;

    if (ac == 2 && my_strcmp(av[1], HELP_ARG) == 0) {
        write(1, HELP, my_strlen(HELP));
        return 0;
    }
    if (error(ac, av)) {
        return 84;
    }
    tr = struct1(tr, av);
    divi(tr, ac, av);
    compute(tr, ac, av);
    free(tr);
    return 0;
}
