/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(const char *src)
{
    int length = 0;
    char *str = NULL;

    length = my_strlen(src);
    if ((str = malloc(sizeof(char) * (length + 1))) == NULL) {
        return NULL;
    }
    str = my_strcpy(str, src);

    str[length] = '\0';
    return str;
}
