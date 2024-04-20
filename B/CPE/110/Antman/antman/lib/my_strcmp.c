/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../include/my.h"

int my_strcmp(const char *strA, const char *strB)
{
    int diff = 0;

    while (*strA && *strA == *strB) {
        strA++;
        strB++;
    }
    diff = *strA - *strB;
    return diff;
}
