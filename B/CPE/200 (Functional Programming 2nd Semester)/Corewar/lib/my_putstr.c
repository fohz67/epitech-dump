/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "lib.h"

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
