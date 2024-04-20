/*
** EPITECH PROJECT, 2022
** my_sort_ascii.c
** File description:
** my_sort_ascii.c
*/

#include "../include/my.h"

void my_sort_ascii(int nb, char **tab)
{
    int index = 0;
    int jndex = 0;

    for (index = 1; index < nb; index++) {
        for (jndex = index;
            jndex > 0 && my_strcmp(tab[jndex - 1], tab[jndex]) > 0;
            jndex--) {
            char *temp = tab[jndex - 1];
            tab[jndex - 1] = tab[jndex];
            tab[jndex] = temp;
        }
    }
}
