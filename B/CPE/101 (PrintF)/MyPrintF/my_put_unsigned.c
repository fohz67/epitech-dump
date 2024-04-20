/*
** EPITECH PROJECT, 2022
** my_put_unsigned.c
** File description:
** My put unsigned
*/

#include "my.h"

int my_put_unsigned(unsigned int nb)
{
    unsigned int power = 1, count = 0;

    while (nb / power > 9)
        power = power * 10;
    while (power >= 1) {
        my_put_char((nb / power) % 10 + 48);
        power = power / 10;
        count = count + 1;
    }
    return count;
}
