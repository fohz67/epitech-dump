/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** graph.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

static int check_exist(int *room, int tunnel, int index)
{
    int exist = 0;

    for (int i = 0; i < index; i++) {
        if (room[i] == tunnel) {
            exist = 1;
        }
    }
    return exist;
}

static int *check_room(anthill *ant)
{
    int *room = NULL;
    int index = 0;
    int exist = 0;

    if ((room = malloc(sizeof(int) * ant->nb_rooms)) == NULL) {
        return NULL;
    }
    for (int i = 0; ant->tunnels[i][0] != -42; i++) {
        exist = check_exist(room, ant->tunnels[i][0], index);
        if (exist == 0) {
            room[index] = ant->tunnels[i][0];
            index++;
        }
        exist = check_exist(room, ant->tunnels[i][1], index);
        if (exist == 0) {
            room[index] = ant->tunnels[i][1];
            index++;
        }
    }
    return room;
}

static void add_end(list_t **graph, list_t *new_element)
{
    list_t *tmp = NULL;

    tmp = (*graph);
    if ((*graph) == NULL) {
        new_element->next = NULL;
        (*graph) = new_element;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_element;
        new_element->next = NULL;
    }
}

static list_t* create_new_element(int room, int dist)
{
    list_t* new_element = NULL;

    if ((new_element = malloc(sizeof(list_t))) == NULL) {
        return NULL;
    }
    new_element->name = room;
    new_element->dist = dist;
    new_element->ptr_link = NULL;
    return new_element;
}

list_t* create_graph(list_t *graph, anthill *ant)
{
    list_t *new_element = NULL;
    int *room = NULL;

    room = check_room(ant);
    for (int i = 0; i < ant->nb_rooms; i++) {
        if ((new_element = create_new_element(room[i], ant->nb_rooms))
        == NULL) {
            return NULL;
        }
        add_end(&graph, new_element);
    }
    if ((graph = create_link(ant, graph)) == NULL) {
        return NULL;
    }
    if ((graph = set_dist(graph, ant)) == NULL) {
        return NULL;
    }
    free(room);
    return graph;
}
