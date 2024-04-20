/*
** EPITECH PROJECT, 2022
** my_put_e.c
** File description:
** My put e
*/

#include "my.h"

static int dispatch(double nb, int digit, char c)
{
    int length = 0;

    if ((int) nb == 0) {
        length = length + display_scientific_z(nb, digit, c);
    } else {
        length = length + display_scientific(nb, digit, c);
    }
    return length;
}

int my_put_e2(double nb, const char *format, int index, char alpha)
{
    char c = format[index], c1 = format[index + 1], c2 = format[index + 2];
    int digit = 0, length = 0, size = 0;

    if (nb < 0) size = 1;

    if (c == '#' && my_get_num(c1) == 1) {
        digit = my_get_digit(format, index, alpha);
        length = my_put_space(format, index, digit + 6 + size);
        if (digit == 0 || c1 == '.' && c2 == alpha)
            digit = -1;
        return length + dispatch(nb, digit, alpha);
    }
    if (c1 == '.' && format[index + 3] == alpha) {
        digit = my_get_digit(format, index, alpha);
        if (c == '#' && (digit == 0 || c1 == '.' && c2 == alpha))
            digit = -1;
        return length + dispatch(nb, digit, alpha);
    }
    return 0;
}

int my_put_e(double nb, const char *format, int index, char alpha)
{
    char c1 = format[index + 1], c2 = format[index + 2];
    int digit = 0, length = 0;

    if (c1 == alpha) {
        digit = 6;
        return length + dispatch(nb, digit, alpha);
    }
    if (c1 == '.' && c2 == alpha) {
        digit = 0;
        return length + dispatch(nb, digit, alpha);
    }
    return length + my_put_e2(nb, format, index, alpha);
}
