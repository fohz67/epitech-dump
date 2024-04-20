/*
** EPITECH PROJECT, 2022
** my_putlong.c
** File description:
** my_putlong.c
*/

#include "../include/my.h"

int my_putlong(long int nb)
{
    long power = 1;
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        count = count + 1;
    }
    while (nb / power > 9)
        power = power * 10;
    while (power >= 1) {
        my_putchar((nb / power) % 10 + 48);
        power = power / 10;
        count = count + 1;
    }
    return count;
}
