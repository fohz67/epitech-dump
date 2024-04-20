/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "../include/my.h"

int my_putstr(const char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        my_putchar(str[index++]);
    }
    return index;
}
