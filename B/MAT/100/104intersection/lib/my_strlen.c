/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "../include/my.h"

int my_strlen(const char *str)
{
    int index = 0;

    while (str[index] != ENDSTR) {
        index = index + 1;
    }
    return index;
}
