/*
** EPITECH PROJECT, 2023
** functions.c
** File description:
** functions.c
*/

#include <unistd.h>
#include "my.h"

void my_putchar(const char c)
{
    write(1, &c, 1);
}

int my_strlen(const char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index = index + 1;
    }
    return index;
}
