/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

int main(int ac, const char **)
{
    anthill *ant = NULL;
    list_t *graph = NULL;

    if (ac != 1) {
        return 84;
    }
    if ((ant = malloc(sizeof(anthill))) == NULL) {
        return 84;
    }
    if (structure(ant) == 84 || parse_data(ant) == 84) {
        return 84;
    }
    if ((graph = create_graph(graph, ant)) == NULL) {
        return 84;
    }
    free_graph(graph);
    my_free_intarray(ant->tunnels);
    free(ant);
    return 0;
}
