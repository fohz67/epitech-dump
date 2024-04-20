/*
** EPITECH PROJECT, 2022
** my_put_f.c
** File description:
** My put f
*/

#include "my.h"

int my_put_f2(double nb, const char *format, int index, char alpha)
{
    char c = format[index], c1 = format[index + 1], c2 = format[index + 2];
    int digit = 0, length = 0, size = 0;

    size = my_get_int_len(nb);
    if (nb < 0) size = my_get_int_len(-nb) + 1;

    if (c == '#' && my_get_num(c1) == 1) {
        digit = my_get_digit(format, index, alpha);
        length = my_put_space(format, index, size + digit + 1);
        if (digit == 0 || c1 == '.' && c2 == alpha)
            digit = -1;
        return length + display_basic(nb, digit);
    }
    if (c1 == '.' && format[index + 3] == alpha) {
        digit = my_get_digit(format, index, alpha);
        if (c == '#' && (digit == 0 || c1 == '.' && c2 == alpha))
            digit = -1;
        return display_basic(nb, digit);
    }
    return 0;
}

int my_put_f(double nb, const char *format, int index, char alpha)
{
    char c1 = format[index + 1], c2 = format[index + 2];
    int digit = 0, length = 0;

    if (c1 == alpha) {
        digit = 6;
        return length + display_basic(nb, digit);
    }
    if (c1 == '.' && c2 == alpha) {
        digit = 0;
        return length + display_basic(nb, digit);
    }
    return length + my_put_f2(nb, format, index, alpha);
}
