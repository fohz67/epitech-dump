/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** structure.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

static int structure2(anthill *ant)
{
    if (ant->tunnels == NULL)
        return 84;
    for (int i = 0; i < 1000; i++) {
        ant->tunnels[i] = malloc(sizeof(int) * 2);
        if (ant->tunnels[i] == NULL) {
            return 84;
        }
        ant->tunnels[i][0] = 0;
        ant->tunnels[i][1] = 0;
    }
    return 0;
}

int structure(anthill *ant)
{
    ant->nb_ant = -1;
    ant->nb_rooms = 0;
    ant->start_room = -1;
    ant->end_room = -1;
    ant->tunnel_index = 0;
    ant->start_index = 0;
    ant->data_index = 0;
    ant->end_index = 0;
    ant->tunnels = NULL;
    ant->tunnels = malloc(sizeof(int *) * 1000);
    if (structure2(ant) == 84) {
        return 84;
    }
    return 0;
}
