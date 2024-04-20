/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-pushswap-benjamin.gayaud
** File description:
** sort.c
*/

#include "../include/my.h"

int sort_order(int ac, int i, struct tabs *my_tabs)
{
    if (order(ac, my_tabs) == 0) {
        display(i, my_tabs);
        return 0;
    }
    my_strcat(my_tabs->list_ope, "pb ");
    my_tabs->list_a = sort_move(ac, 1, 1, my_tabs);
    return 1;
}

int *sort_move(int ac, int pos, int flag, struct tabs *my_tabs)
{
    int i = 0;
    int j = 0;

    while (i < pos) {
        int temp = my_tabs->list_a[j];
        while (j < ac - 2) {
            my_tabs->list_a[j] = my_tabs->list_a[j + 1];
            j++;
        }
        if (flag == 0) {
            my_strcat(my_tabs->list_ope, "ra ");
        }
        my_tabs->list_a[ac - 2] = temp;
        j = 0;
        i++;
    }
    return my_tabs->list_a;
}

int sort(int ac, struct tabs *my_tabs)
{
    int i = 0;
    int max = ac;
    int pos = 0;

    while (i < max - 1) {
        pos = minimum(ac, my_tabs);
        my_tabs->list_b[i] = my_tabs->list_a[pos];
        my_tabs->list_a = sort_move(ac, pos, 0, my_tabs);
        i++;
        if (sort_order(ac, i, my_tabs) == 0) {
            return 0;
        }
        ac--;
    }

    display(max, my_tabs);
    return 0;
}
