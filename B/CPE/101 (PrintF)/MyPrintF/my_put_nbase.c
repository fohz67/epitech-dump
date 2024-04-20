/*
** EPITECH PROJECT, 2022
** my_put_nbase.c
** File description:
** My put n base
*/

#include "my.h"

int display(char *str_char, int index)
{
    int length = 0;

    for (int rev_index = index - 1; rev_index >= 0; rev_index--)
        length = length + my_put_char(str_char[rev_index]);
    return length;
}

int alpha(char c)
{
    if (c == 'b')
        return 2;
    if (c == 'B')
        return 2;
    if (c == 'o')
        return 8;
    if (c == 'x')
        return 16;
    if (c == 'X')
        return 16;
    if (c == 'p')
        return 16;
}

int modifier(char c, char c_before)
{
    int length = 0;

    if (c == 'p')
        return length + my_put_string("0x");
    if (c_before == '#') {
        if (c == 'b')
            return length + my_put_string("0b");
        if (c == 'B')
            return length + my_put_string("0B");
        if (c == 'o')
            return length + my_put_char('0');
        if (c == 'x')
            return length + my_put_string("0x");
        if (c == 'X')
            return length + my_put_string("0X");
    }
    return length;
}

int modifier_space(char c, char c_before)
{
    int length = 0;

    if (c == 'p')
        return 2;
    if (c_before == '#') {
        if (c == 'b' || c == 'B' || c == 'x' || c == 'X')
            return 2;
        if (c == 'o')
            return 1;
    }
    return length;
}

int my_put_nbase(unsigned int nb, const char *format, int index, int refind)
{
    char str_char[64] = {0};
    char str_table[16] = "0123456789abcdef";
    char str_table_maj[16] = "0123456789ABCDEF";
    char c = format[index + refind +1], c_before = format[index];
    int length = 0, base = 0, indx = 0, mlen = 0;

    if (nb == 0) return my_put_char('0');
    base = alpha(c);

    while (nb != 0) {
        if (c == 'X' || c == 'B') str_char[indx++] = str_table_maj[nb % base];
        else
            str_char[indx++] = str_table[nb % base];
        nb = nb / base;
    }
    mlen = modifier_space(c, c_before);
    if (c_before == '#') length = my_put_space(format, index, indx + mlen);

    length = length + modifier(c, c_before);
    return length + display(str_char, indx);
}
