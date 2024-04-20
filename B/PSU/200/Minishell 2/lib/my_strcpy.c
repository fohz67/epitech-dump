/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char* dest, const char *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

char *my_stricpy(char* dest, const char* src, int n)
{
    int len = 0;

    len = my_strlen(src);
    if (n >= len) {
        dest[0] = '\0';
        return dest;
    }
    return my_strcpy(dest, src + n);
}
