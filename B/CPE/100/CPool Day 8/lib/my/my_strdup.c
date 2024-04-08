/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** My str dup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int strlen = my_strlen(src);
    char *str = malloc(sizeof(char) * (strlen + 1));

    str = my_strcpy(str, src);
    str[strlen] = '\0';
    return str;
}
