/*
** EPITECH PROJECT, 2022
** my_calstr.c
** File description:
** my_calstr.c
*/

#include "../include/my.h"

int my_nbline(const char *str)
{
    int index = 0;
    int result = 0;
    char nb[64] = {0};

    while (str[index] >= '0' && str[index] <= '9') {
        nb[index] = str[index];
        index = index + 1;
    }
    result = my_getnbr(nb);
    return result;
}

int my_nbcheck(char **tab)
{
    if (tab[1][1] == '\0') {
        return 1;
    }
    if (tab[2][0] == 'E') {
        return 2;
    }
    return NO_VALUE;
}
