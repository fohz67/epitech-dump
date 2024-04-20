/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** parsing.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"

int parse_data(anthill *ant)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != -1) {
        if (line == NULL || my_strlen(line) <= 1) {
            return 84;
        }
        if (!(line[0] == '#' && line[1] != '#') &&
        read_data(line, ant) == 84) {
            free(line);
            return 84;
        }
    }
    ant->tunnels[ant->tunnel_index][0] = -42;
    free(line);
    return 0;
}
