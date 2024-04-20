/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** My putchar
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
