/*
** EPITECH PROJECT, 2022
** my_put_g.c
** File description:
** My put g
*/

#include "my.h"

int space(int digit, int size)
{
    if (size == 6) {
        digit = 6;
    }
    if (size < 6) {
        digit = 7;
    }
    if (size > 6) {
        digit = 10;
    }
    return digit;
}

static int dispatch(int size, double nb, int digit, char alpha)
{
    int length = 0;

    if (size == 6) {
        length = length + my_put_int(nb + 0.5);
        if (alpha == '#') {
            length = length + my_put_char('.');
        }
    }
    if (size < 6) {
        if (digit >= 6 - size) {
            digit = 6 - size - 1;
        }
        length = length + display_basic(nb, digit);
    }
    if (size > 6) {
        length = length + display_superior(nb, size, alpha);
    }
    return length;
}

int my_put_g(double nb, const char *format, int index, char alpha)
{
    char c = format[index], c1 = format[index + 1], c2 = format[index + 2];
    int size = 0, digit = 0, length = 0;

    size = my_get_int_len(nb);
    if (nb < 0) size = my_get_int_len(-nb);

    if (c1 == alpha) {
        digit = 6 - size;
        return length + dispatch(size, nb, digit, alpha);
    }
    if (c1 == '.' && c2 == alpha) {
        digit = 0;
        return length + dispatch(size, nb, digit, alpha);
    }
    return length;
}
