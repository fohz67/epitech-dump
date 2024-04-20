/*
** EPITECH PROJECT, 2022
** my_get_nbr.c
** File description:
** my_get_nbr.c
*/

#include "../include/my.h"

int my_getnbr(const char *str)
{
    int index = 0, number = 0, negative = 1;

    if (str[0] == '-') {
        negative = -1;
        index = 1;
    }

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            number = number * 10 + str[index++] - '0';
        } else {
            return negative * number;
        }
    }
    return negative * number;
}
