/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "../include/my.h"

char *my_strcpy(char *dest, const char *src)
{
    int index = 0;

    for (index; src[index] != '\0'; index++) {
        dest[index] = src[index];
    }
    dest[index] = '\0';
    return dest;
}
