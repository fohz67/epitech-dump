/*
** EPITECH PROJECT, 2022
** mini_putchar.c
** File description:
** Mini putchar
*/

#include <unistd.h>

int mini_putchar(char c)
{
    int count = 1;

    write(1, &c, 1);
    return count;
}
