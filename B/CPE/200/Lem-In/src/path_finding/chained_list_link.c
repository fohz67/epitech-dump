/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** chained_list_link.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"

void print_graph(list_t *graph)
{
    list_t *tmp = NULL;

    tmp = graph;
    for (; tmp != NULL; tmp = tmp->next) {
        my_putnbr(tmp->name);
        my_putstr(" ->-> ");
        for (link_t *tmp2 = tmp->ptr_link; tmp2 != NULL; tmp2 = tmp2->next) {
                my_putnbr(tmp2->link_room->name);
                my_putstr(" -> ");
        }
        my_putstr("\n");
    }
}

list_t *get_node(list_t *graph, int index)
{
    list_t *tmp = NULL;

    tmp = graph;
    for (; tmp != NULL && tmp->name != index; tmp = tmp->next);
    return tmp;
}

link_t *add_link(list_t *graph, link_t *ptr_link, int room)
{
    link_t *new_element = NULL;
    link_t *tmp = NULL;

    if ((new_element = malloc(sizeof(link_t))) == NULL) {
        return NULL;
    }
    new_element->link_room = NULL;
    new_element->link_room = get_node(graph, room);
    new_element->next = NULL;
    tmp = ptr_link;
    if (ptr_link == NULL) {
        new_element->next = NULL;
        ptr_link = new_element;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_element;
        new_element->next = NULL;
    }
    return ptr_link;
}

list_t *create_link(anthill *ant, list_t *graph)
{
    list_t *tmp = NULL;

    for (int i = 0; ant->tunnels[i][0] != -42; i++) {
        tmp = get_node(graph, ant->tunnels[i][0]);
        if (tmp == NULL)
            return NULL;
        tmp->ptr_link = add_link(graph, tmp->ptr_link, ant->tunnels[i][1]);
        if (tmp->ptr_link == NULL)
            return NULL;
        tmp = get_node(graph, ant->tunnels[i][1]);
        if (tmp == NULL)
            return NULL;
        tmp->ptr_link = add_link(graph, tmp->ptr_link, ant->tunnels[i][0]);
        if (tmp->ptr_link == NULL)
            return NULL;
    }
    return graph;
}
