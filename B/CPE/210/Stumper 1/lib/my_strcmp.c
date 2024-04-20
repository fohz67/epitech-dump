/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../include/my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int index = 0;

    while (index < n && s1[index] != '\0' &&
    s2[index] != '\0' && s1[index] == s2[index]) {
        index++;
    }
    if (index == n) {
        return 0;
    } else {
        return s1[index] - s2[index];
    }
    return 0;
}

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
