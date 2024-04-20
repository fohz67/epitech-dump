/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-pushswap-benjamin.gayaud
** File description:
** order.c
*/

#include "../include/my.h"

int order2(int i, int ac, struct tabs *my_tabs)
{
    int j = i + 1;

    while (j < ac - 1) {
        if (my_tabs->list_a[i] > my_tabs->list_a[j]) {
            return 84;
        }
        j++;
    }
    return 0;
}

int order(int ac, struct tabs *my_tabs)
{
    int i = 0;

    while (i < ac - 1) {
        if (order2(i, ac, my_tabs) == 84) {
            return 84;
        }
        i++;
    }
    return 0;
}
