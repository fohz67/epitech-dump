/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** My print f
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

int replace_format(const char *format, va_list list, int index, int refind);

int replace_format3(const char *format, va_list list, int index, int refind)
{
    char c = format[index + 1];

    if (c == 'g' || c == 'G') {
        return my_put_g(va_arg(list, double), format, index - refind, c);
    }
    if (c == 'e' || c == 'E') {
        return my_put_e(va_arg(list, double), format, index - refind, c);
    }
    if (c == 'f' || c == 'F') {
        return my_put_f(va_arg(list, double), format, index - refind, c);
    }

    return 0;
}

int replace_format2(const char *format, va_list list, int index, int refind)
{
    char c = format[index + 1];

    if (c > 47 && c < 58 || c == '.') {
        return
        replace_format(format, list, index + 1, refind + 1);
    }
    if (c == '#') {
        return
        replace_format(format, list, index + 1, refind);
    }
    if (c == 'b' || c == 'B' || c == 'o' || c == 'x' || c == 'X' || c == 'p') {
        return
        my_put_nbase(va_arg(list, int), format, index - refind, refind);
    }

    return replace_format3(format, list, index, refind);;
}

int replace_format(const char *format, va_list list, int index, int refind)
{
    char c = format[index + 1];

    if (c == 'd' || c == 'i') {
        return my_put_int_format(va_arg(list, int), format, index - refind);
    }
    if (c == 'c') {
        return my_put_char(va_arg(list, int));
    }
    if (c == 's') {
        return
        my_put_string_format(va_arg(list, char *), format, index - refind);
    }
    if (c == '%') {
        return my_put_char('%');
    }
    if (c == 'u') {
        return
        my_put_u_format(va_arg(list, unsigned int), format, index - refind);
    }
    return replace_format2(format, list, index, refind);
}

int get_index(const char *format, va_list list, int index)
{
    int a = 2;

    if (format[index + 1] == '.' || format[index + 1] == '#') {
        while (my_get_alpha(format[a]) == 0)
            a = a + 1;
        return index + a + 1;
    }
    return index + 2;
}

int my_printf(const char *format, ...)
{
    int index = 0, length = 0, refind = 0;
    va_list list;

    va_start(list, format);
    while (format[index] != '\0') {
        if (format[index] == '%' && format[index + 1] == 'n') {
            int * ptr = va_arg(list, int *);
            *ptr = length;
            index = index + 2;
        }
        if (format[index] == '%') {
            length = length + replace_format(format, list, index, refind);
            index = get_index(format, list, index);
        } else {
            length = length + my_put_char(format[index]);
            index = index + 1;
        }
    }
    va_end(list);
    return length;
}
