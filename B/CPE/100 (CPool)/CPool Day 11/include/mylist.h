/*
** EPITECH PROJECT, 2022
** mylist.h
** File description:
** My list
*/

#ifndef MY_LIST
    #define MY_LIST

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

#endif
