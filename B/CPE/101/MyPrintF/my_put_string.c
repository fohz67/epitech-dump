/*
** EPITECH PROJECT, 2022
** my_put_string.c
** File description:
** My put string
*/

#include "my.h"

int my_put_string(const char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        my_put_char(str[index]);
        index = index + 1;
    }
    return index;
}
