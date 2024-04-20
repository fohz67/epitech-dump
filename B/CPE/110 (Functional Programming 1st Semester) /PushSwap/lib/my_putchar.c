/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** my_putchar.c
*/

#include "../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
