/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include "lib.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
