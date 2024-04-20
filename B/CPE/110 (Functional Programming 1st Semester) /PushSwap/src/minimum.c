/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-pushswap-benjamin.gayaud
** File description:
** minimum.c
*/

#include "../include/my.h"

int minimum(int ac, struct tabs *my_tabs)
{
    int i = 0;
    int min = MAX_INT_VALUE;
    int pos = 0;

    while (i < ac - 1) {
        if (min > my_tabs->list_a[i]) {
            min = my_tabs->list_a[i];
            pos = i;
        }
        i++;
    }
    return pos;
}
