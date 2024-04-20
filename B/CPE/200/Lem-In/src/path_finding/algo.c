/*
** EPITECH PROJECT, 2023
** algo
** File description:
** algo
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

int get_min(link_t *link)
{
    int min = 0;
    int min_room = 0;
    link_t *tmp = NULL;

    tmp = link;
    min = link->link_room->dist;
    min_room = tmp->link_room->name;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->link_room->dist < min) {
            min = tmp->link_room->dist;
            min_room = tmp->link_room->name;
        }
    }
    return min_room;
}

int *get_moves(list_t *graph, anthill *ant)
{
    int *move = NULL;
    list_t *tmp = NULL;
    int i = 0;

    if ((move = malloc(sizeof(int) * (ant->nb_rooms + 1))) == NULL)
        return NULL;
    tmp = get_node(graph, ant->start_room);
    while (tmp->name != ant->end_room) {
        move[i] = get_min(tmp->ptr_link);
        tmp = get_node(graph, move[i]);
        i++;
    }
    move[i] = -1;
    return move;
}

void print_moves(list_t *graph, anthill *ant)
{
    int *move = NULL;

    my_putstr("#moves\n");
    move = get_moves(graph, ant);
    my_putstr("P1-");
    my_putnbr(move[0]);
    my_putstr("\n");
}
