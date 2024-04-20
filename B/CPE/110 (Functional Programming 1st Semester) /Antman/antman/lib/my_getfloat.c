/*
** EPITECH PROJECT, 2022
** my_getfloat.c
** File description:
** my_getfloat.c
*/

#include "../include/my.h"

float my_getfloat(const char *str)
{
    int i = 0;
    float number = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + str[i++] - '0';
        } else {
            return number;
        }
    }
    return number;
}
