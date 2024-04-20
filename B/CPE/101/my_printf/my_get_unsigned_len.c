/*
** EPITECH PROJECT, 2022
** my_get_unsigned_len.c
** File description:
** My get unsigned len
*/

#include "my.h"

int my_get_unsigned_len(unsigned int nb)
{
    unsigned int power = 1, count = 0;

    while (nb / power > 9)
        power = power * 10;
    while (power >= 1) {
        power = power / 10;
        count = count + 1;
    }
    return count;
}
