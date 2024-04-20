/*
** EPITECH PROJECT, 2022
** generate.c
** File description:
** generate.c
*/

#include "../include/my.h"

int generate_buf(char **av, char *buffer, struct square b, struct generate g)
{
    while (g.index < g.nbmax + g.nb + g.nblen + 1) {
        if (g.kndex == g.nb) {
            buffer[g.index] = '\n';
            g.index = g.index + 1;
            g.kndex = 0;
        } else {
            buffer[g.index] = av[2][g.jndex];
            g.index = g.index + 1;
            g.jndex = g.jndex + 1;
            g.kndex = g.kndex + 1;
        }
        if (av[2][g.jndex] == '\0') {
            g.jndex = 0;
        }
    }
    buffer[g.index] = '\n';
    buffer[g.index + 1] = '\0';
    return handling(buffer, g.nbmax + g.nb + g.nblen + 1, b);
}

int generate(char **av)
{
    struct generate g = {0, 0, 0, 0, 0, 0};
    struct square b = {0, 0, 0, 0, 0, 0};

    g.nb = my_getnbr(av[1]);
    g.nblen = my_nbrlen(g.nb);
    g.index = g.nblen + 1;
    g.nbmax = g.nb * g.nb;

    if (g.nb == 1 && av[2][0] == 'o') {
        my_putstr("o\n");
        return SUCCESS;
    } else if (g.nb < 0 || (av[1][0] < '0' && av[1][0] > 9)) {
        return ERROR;
    } else {
        char *buffer = malloc(sizeof(char) * (g.nbmax + g.nb + g.nblen + 3));
        buffer = my_strcpy(buffer, av[1]);
        buffer[g.nblen] = '\n';
        return generate_buf(av, buffer, b, g);
    }
    return SUCCESS;
}
