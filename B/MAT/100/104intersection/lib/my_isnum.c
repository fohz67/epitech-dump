/*
** EPITECH PROJECT, 2022
** my_isnum.c
** File description:
** my_isnum.c
*/

#include "../include/my.h"

int my_isnum(const char *str)
{
    int index = 0;

    while (str[index] != ENDSTR) {
        if ((str[index] < '0' || str[index] > '9') &&
        str[index] != '-' && str[index] != '.') {
            return ERROR;
        }
        index = index + 1;
    }
    return SUCCESS;
}
