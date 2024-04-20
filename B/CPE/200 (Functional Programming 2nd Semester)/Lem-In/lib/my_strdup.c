/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "lemin.h"

char *my_strdup(const char *src)
{
    int len = 0;
    char *dest = NULL;

    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL) {
        return NULL;
    }
    dest = my_strcpy(dest, src);
    dest[len] = '\0';
    return dest;
}

char* my_strndup(const char* src, int n)
{
    int len = 0;
    char* dest = NULL;

    len = my_strlen(src) - n;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL) {
        return NULL;
    }
    my_strncpy(dest, src, len);
    dest[len] = '\0';
    return dest;
}

char* my_stridup(const char* src, int n)
{
    int len = my_strlen(src);

    if (n >= len) {
        return NULL;
    }
    return my_strdup(src + n);
}
