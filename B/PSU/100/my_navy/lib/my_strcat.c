/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    char *save = dest;

    while (*dest) {
        dest++;
    }
    while ((*dest = *src) != '\0') {
        dest++;
        src++;
    }
    return save;
}
