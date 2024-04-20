/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include "ginger.h"

static int arg_map(const char **av)
{
    if (av[1][1] == 'f') {
        return 2;
    }
    if (av[3][1] == 'f') {
        return 4;
    }
    return 0;
}

int main(int ac, const char **av)
{
    char *buffer = NULL;
    char **map = NULL;
    int pos_map = 0;

    if (manage_errors(ac, av) == 84) {
        return 84;
    }
    pos_map = arg_map(av);
    if ((buffer = file_content(av[pos_map])) == NULL) {
        return 84;
    }
    if ((map = load_map(av[pos_map], buffer)) == NULL) {
        return 84;
    }
    engine(av, buffer, map);
    free(buffer);
    return 0;
}
