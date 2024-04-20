/*
** EPITECH PROJECT, 2022
** my_get_int.c
** File description:
** My get int
*/

#include "my.h"

int my_get_int(const char *str)
{
    int index = 0, number = 0;

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            number = number * 10 + str[index++] - '0';
        } else {
            return number;
        }
    }
    return number;
}
