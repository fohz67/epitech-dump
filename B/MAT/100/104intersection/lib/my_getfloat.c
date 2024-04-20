/*
** EPITECH PROJECT, 2022
** my_getfloat.c
** File description:
** my_getfloat.c
*/

#include "../include/my.h"

float my_getfloat(const char *str)
{
    int index = 0;
    float number = 0;

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            number = number * 10 + str[index++] - '0';
        } else {
            return number;
        }
    }
    return number;
}
