/*
** EPITECH PROJECT, 2022
** my_get_string_len.c
** File description:
** My get string len
*/

#include "my.h"

int my_get_string_len(const char *str)
{
    int index = 0;

    while (str[index] != '\0')
        index = index + 1;
    return index;
}
