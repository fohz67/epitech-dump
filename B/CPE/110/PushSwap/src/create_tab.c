/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-pushswap-benjamin.gayaud
** File description:
** create_tab.c
*/

#include "../include/my.h"

int malloc_int(int ac, struct tabs *my_tabs)
{
    my_tabs->list_a = malloc(sizeof(int) * ac);
    my_tabs->list_b = malloc(sizeof(int) * ac);
    my_tabs->list_ope = malloc(sizeof(char) * (((ac * 3) * (ac * 3)) + 1));

    if (my_tabs->list_a == NULL ||
        my_tabs->list_b == NULL ||
        my_tabs->list_ope == NULL) {
        return 84;
    }
    return 0;
}

void swipe(int ac, struct tabs *my_tabs)
{
    if (my_tabs->list_a[0] > my_tabs->list_a[1]) {
        my_strcat(my_tabs->list_ope, "sa ");

        int temp = my_tabs->list_a[0];
        my_tabs->list_a[0] = my_tabs->list_a[1];
        my_tabs->list_a[1] = temp;
    }
}

int create_tab(int ac, const char **av)
{
    int i = 0;
    int *list_a = NULL;
    int *list_b = NULL;
    char *list_ope = NULL;
    struct tabs my_tabs = {list_a, list_b, list_ope};

    if (malloc_int(ac, &my_tabs) == 84)
        return 84;
    while (i < ac - 1) {
        if (error(av[i + 1]) == 84)
            return 84;
        my_tabs.list_a[i] = my_getnbr(av[i + 1]);
        i++;
    }
    swipe(ac, &my_tabs);
    sort(ac, &my_tabs);
    free(list_a);
    free(list_b);
    free(list_ope);
    return 0;
}
