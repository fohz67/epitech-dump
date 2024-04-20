/*
** EPITECH PROJECT, 2022
** my_put_int_format.c
** File description:
** My put int format
*/

#include "my.h"

int my_put_int_format(int nb, const char *format, int index)
{
    int power = 1, count = 0;

    if (format[index] == '#')
        count = my_put_space(format, index, my_get_int_len(nb));

    if (nb < 0) {
        my_put_char('-');
        nb = nb * -1;
        count = count + 1;
    }
    while (nb / power > 9)
        power = power * 10;
    while (power >= 1) {
        my_put_char((nb / power) % 10 + 48);
        power = power / 10;
        count = count + 1;
    }
    return count;
}
