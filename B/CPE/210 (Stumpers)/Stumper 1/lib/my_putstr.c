/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "../include/my.h"

int my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
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
