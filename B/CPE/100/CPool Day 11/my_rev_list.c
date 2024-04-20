/*
** EPITECH PROJECT, 2022
** my_rev_list.c
** File description:
** My rev list
*/

#include <stddef.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *list = begin;
    linked_list_t *list_temp = 0;
    linked_list_t *list_next;

    while (list->next != NULL) {
        list_next = list->next;
        list->next = list_temp;
        list_temp = list;
        list = list_next;
    }
    list->next = list_temp;
    *begin = list;
}
