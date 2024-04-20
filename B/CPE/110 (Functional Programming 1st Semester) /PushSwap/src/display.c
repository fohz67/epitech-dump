/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-pushswap-benjamin.gayaud
** File description:
** display.c
*/

#include "../include/my.h"

void display_pa(int max, struct tabs *my_tabs)
{
    int i = 0;

    while (i < max - 1) {
        my_strcat(my_tabs->list_ope, "pa ");
        i++;
    }
}

void display(int max, struct tabs *my_tabs)
{
    display_pa(max, my_tabs);
    int length = my_strlen(my_tabs->list_ope);

    if (length > 0) {
        my_tabs->list_ope[length - 1] = '\n';
    } else {
        my_strcat(my_tabs->list_ope, "\n");
    }
    write(1, my_tabs->list_ope, my_strlen(my_tabs->list_ope));
}
