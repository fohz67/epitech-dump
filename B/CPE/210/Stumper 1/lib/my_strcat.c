/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** cat
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int dest_len = 0;
    int i = 0;

    dest_len = my_strlen(dest);
    for (i = 0 ;src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
