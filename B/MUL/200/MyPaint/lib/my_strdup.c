/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "paint.h"

char *my_strdup(const char *src)
{
    int len = 0;
    char *dest = NULL;

    len = my_strlen(src);
    if ((dest = malloc(sizeof(char) * (len + 1))) == NULL) {
        return NULL;
    }
    dest = my_strcpy(dest, src);

    dest[len] = '\0';
    return dest;
}
