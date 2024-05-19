/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error.c
*/

#include "my.h"

bool is_digit(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
