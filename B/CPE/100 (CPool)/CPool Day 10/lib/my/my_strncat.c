/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** My str n cat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int destlen = my_strlen(dest);

    for (a; src[a] != '\0' && a < nb; a++) {
        dest[destlen + a] = src[a];
    }
    dest[destlen + a] = '\0';
    return dest;
}
