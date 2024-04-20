/*
** EPITECH PROJECT, 2022
** my_display.alpha
** File description:
** My display
*/

#include "my.h"

int display_scientific_z(double nb, int digit, char alpha)
{
    int length = 0, size = 0;
    double after = (double) nb - (int) nb;

    if (nb == 0) {
        length = length + my_put_string("0.");
        length = length + my_put_zero(0, my_get_power(digit));
        length = length + my_put_char(alpha);
        length = length + my_put_string("+00");
        return length;
    }
    while ((int) nb == 0) {
        nb = nb * 10;
        size = size + 1;
    }
    if (after == 0) after = nb / 10;
    length = length + display_basic(nb, digit);
    length = length + my_put_char(alpha);
    length = length + my_put_string("-0");
    length = length + my_put_int(size);
    return length;
}

int display_scientific(double nb, int digit, char alpha)
{
    int length = 0, nblen = 0;
    double after = (double) nb - (int) nb;

    nblen = my_get_int_len((int) nb);
    nb = nb / my_get_power(nblen - 1);

    length = length + display_basic(nb, digit);
    length = length + my_put_char(alpha);
    length = length + my_put_string("+0");
    length = length + my_put_int(nblen - 1);
    return length;
}

int display_superior(double nb, int size, char alpha)
{
    int length = 0, power = 0, a = 0, b = 0;
    double after = (double) nb - (int) nb;

    power = my_get_power(size - 1);

    a = nb / power;
    b = nb - a * power;

    length = length + my_put_int(a);
    length = length + my_put_char('.');

    size = my_get_int_len(b);
    power = my_get_power(size - 5);

    length = length + my_put_int((b + 5) / power);
    length = length + my_put_char(alpha - 2);
    length = length + my_put_string("+0");
    length = length + my_put_int(size);

    return length;
}

int display_advanced(double nb, int digit)
{
    int length = 0, zero = 0, len1 = 0, len2 = 0;
    double after = (double) nb - (int) nb;
    long long int power;

    power = my_get_power(digit);
    len1 = my_get_int_len(after * power);
    len2 = my_get_int_len(after * power + 0.5);

    if (len2 > len1) {
        length = length + my_put_int(nb + 1);
        length = length + my_put_char('.');
        length = length + my_put_zero(0, power);
    } else {
        length = length + my_put_int(nb);
        length = length + my_put_char('.');
        length = length + my_put_zero(after * power + 0.5, power);
        if ((int) (after * power + 0.5) != 0)
            length = length + my_put_int(after * power + 0.5);
    }
    return length;
}

int display_basic(double nb, int digit)
{
    int length = 0;

    if (nb < 0) {
        nb = - nb;
        length = length + my_put_char('-');
    }
    if (digit == 0) {
        length = length + my_put_int(nb + 0.5);
    } else if (digit == -1) {
        length = length + my_put_int(nb + 0.5);
        length = length + my_put_char('.');
    } else {
        length = length + display_advanced(nb, digit);
    }
    return length;
}
