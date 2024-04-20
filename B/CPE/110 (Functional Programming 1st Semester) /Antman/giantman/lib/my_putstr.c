/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "../include/my.h"

int my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return i;
}
