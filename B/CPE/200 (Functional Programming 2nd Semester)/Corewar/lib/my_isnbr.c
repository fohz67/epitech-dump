/*
** EPITECH PROJECT, 2023
** my_isnbr.c
** File description:
** my_isnbr.c
*/

#include <stdbool.h>

bool my_isnbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
