/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "../include/my.h"

int my_getnbr(const char *str)
{
    int i = 0;
    long int number = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + str[i++] - '0';
        } else {
            return number;
        }
    }
    return number;
}
