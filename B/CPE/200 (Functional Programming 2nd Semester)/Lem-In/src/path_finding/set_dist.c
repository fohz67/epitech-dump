/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** set_dist.c
*/

#include <stdlib.h>
#include "lemin.h"

void print_dist(list_t *graph)
{
    list_t *tmp = NULL;

    tmp = graph;
    for (; tmp != NULL; tmp = tmp->next) {
        my_putnbr(tmp->name);
        my_putstr(" ->-> ");
        my_putnbr(tmp->dist);
        my_putstr("\n");
    }
}

static stack_t *add_back_stack(stack_t *stack, list_t *graph)
{
    stack_t *new_element = NULL;
    stack_t *tmp = NULL;

    if ((new_element = malloc(sizeof(stack_t))) == NULL) {
        return NULL;
    }
    new_element->room = graph;
    new_element->next = NULL;
    tmp = stack;
    if (stack == NULL) {
        new_element->next = NULL;
        stack = new_element;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_element;
        new_element->next = NULL;
    }
    return stack;
}

static void free_stack(stack_t *stack)
{
    stack_t *tmp = NULL;

    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

static stack_t *add_condition(stack_t *stack, int i)
{
    for (link_t *tmp2 = stack->room->ptr_link; tmp2 != NULL;
    tmp2 = tmp2->next) {
        if (tmp2->link_room->dist > i) {
            tmp2->link_room->dist = i;
            stack = add_back_stack(stack, tmp2->link_room);
        }
    }
    return stack;
}

list_t *set_dist(list_t *graph, anthill *ant)
{
    list_t *tmp = NULL;
    stack_t *stack = NULL;
    int i = 0;

    tmp = get_node(graph, ant->end_room);
    if (tmp == NULL)
        return NULL;
    tmp->dist = 0;
    stack = add_back_stack(stack, tmp);
    if (stack == NULL)
        return NULL;
    for (; stack != NULL; stack = stack->next) {
        i = stack->room->dist + 1;
        if ((stack = add_condition(stack, i)) == NULL)
            return NULL;
    }
    free_stack(stack);
    return graph;
}
