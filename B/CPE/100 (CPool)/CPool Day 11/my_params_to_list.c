/*
** EPITECH PROJECT, 2022
** my_params_to_list.c
** File description:
** My params to list
*/

#include <stddef.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/mylist.h"

static int my_putlist(linked_list_t **list, char * data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;

    for (int a = 0; a < ac; a++) {
        my_putlist(&list, av[a]);
    }
    return list;
}
