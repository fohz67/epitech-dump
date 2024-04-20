/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "../include/my.h"

int my_getnbr(const char *str)
{
    int index = 0;
    long int number = 0;

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            number = number * 10 + str[index++] - '0';
        } else {
            return number;
        }
    }
    return number;
}
