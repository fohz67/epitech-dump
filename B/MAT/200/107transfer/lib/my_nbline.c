/*
** EPITECH PROJECT, 2022
** my_nbline.c
** File description:
** my_nbline.c
*/

#include "transfer.h"

int my_nbline(const char *str)
{
    int i = 0;
    int div_result = 0;
    char nb[64] = {0};

    while (str[i] >= '0' && str[i] <= '9') {
        nb[i] = str[i];
        i = i + 1;
    }
    div_result = my_getnbr(nb);
    return div_result;
}
