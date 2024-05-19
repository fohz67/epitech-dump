/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "transfer.h"

int my_putstr(const char *str)
{
    int i = 0;

    write(1, str, my_strlen(str));
    return i;
}

int my_puts(const char *str, int status, int enter)
{
    int i = 0;

    write(status, str, my_strlen(str));
    if (enter == 1) {
        my_putchar('\n');
    }
    return i;
}
