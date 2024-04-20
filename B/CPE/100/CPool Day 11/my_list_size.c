/*
** EPITECH PROJECT, 2022
** my_list_size.c
** File description:
** My list size
*/

#include <stddef.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t* list = begin;
    int a;

    for (a = 0; list != NULL; a++) {
        list = list->next;
    }
    return a;
}
