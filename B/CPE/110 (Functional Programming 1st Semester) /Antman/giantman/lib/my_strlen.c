/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "../include/my.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
