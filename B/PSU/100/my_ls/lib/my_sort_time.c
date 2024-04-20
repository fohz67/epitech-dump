/*
** EPITECH PROJECT, 2022
** my_sort_time.c
** File description:
** my_sort_time.c
*/

#include "../include/my.h"

void my_sort_time(int nb, char **tab, const char *path)
{
    int index = 0;
    int jindex = 0;

    for (index = 1; index < nb; index++) {
        for (jindex = index;
            jindex > 0
            && timecheck(tab, path, jindex - 1)
            < timecheck(tab, path, jindex);
            jindex--) {
            char *temp = tab[jindex - 1];
            tab[jindex - 1] = tab[jindex];
            tab[jindex] = temp;
        }
    }
}
