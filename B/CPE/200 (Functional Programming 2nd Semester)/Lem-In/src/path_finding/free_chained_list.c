/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** free_chained_list.c
*/

#include <stdlib.h>
#include "lemin.h"

void free_link(link_t *ptr_link)
{
    link_t *tmp = NULL;

    while (ptr_link != NULL) {
        tmp = ptr_link;
        ptr_link = ptr_link->next;
        free(tmp);
    }
}

void free_graph(list_t *graph)
{
    list_t *tmp = NULL;

    while (graph != NULL) {
        tmp = graph;
        graph = graph->next;
        free_link(tmp->ptr_link);
        free(tmp);
    }
}
