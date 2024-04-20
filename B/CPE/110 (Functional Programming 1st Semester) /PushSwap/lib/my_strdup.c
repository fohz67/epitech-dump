/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "../include/my.h"

char *my_strdup(const  char *src)
{
    int length = 0;
    char *str = NULL;

    length = my_strlen(src);
    str = malloc(sizeof(char) * (length + 1));
    str = my_strcpy(str, src);

    str[length] = '\0';
    return str;
}
