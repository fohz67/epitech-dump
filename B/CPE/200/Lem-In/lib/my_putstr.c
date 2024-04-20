/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

int my_putstr(const char *str)
{
    int i = 0;

    write(1, str, my_strlen(str));
    return i;
}

int my_puterror(const char *str)
{
    int i = 0;

    write(2, str, my_strlen(str));
    return i;
}

int my_putstr_parser(const char *str)
{
    int i = 0;
    char *strB = NULL;

    if (str[0] == '#') {
        return my_putstr(str);
    }
    strB = my_strdup(str);
    if (strB == NULL) {
        return my_putstr(str);
    }
    for (; strB[i] != '\0' && strB[i] != '#'; i++);
    strB[i - 1] = '\n';
    strB[i] = '\0';
    my_putstr(strB);
    free(strB);
    return 0;
}
