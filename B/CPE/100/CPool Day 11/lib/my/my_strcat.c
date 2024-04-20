/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** My str cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int destlen = my_strlen(dest);

    for (a; src[a] != '\0'; a++) {
        dest[destlen + a] = src[a];
    }
    dest[destlen + a] = '\0';
    return dest;
}
