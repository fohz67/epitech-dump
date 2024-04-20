/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** Mini print f
*/

#include <stdarg.h>
#include <stddef.h>

int mini_putchar(char c);
int mini_putnbr(int nb);
int mini_putstr(char const *str);

int replace_format(const char *format, va_list list, int index)
{
    if (format[index + 1] == 'i' || format[index + 1] == 'd')
        return mini_putnbr(va_arg(list, int));
    if (format[index + 1] == 'c')
        return mini_putchar(va_arg(list, int));
    if (format[index + 1] == 's')
        return mini_putstr(va_arg(list, char *));
    if (format[index + 1] == '%')
        return mini_putchar('%');
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int index = 0;
    int length = 0;

    va_start(list, format);
    while (format[index] != '\0') {
        if (format[index] == '%') {
            length = length + replace_format(format, list, index);
            index = index + 2;
        } else {
            length = length + mini_putchar(format[index]);
            index = index + 1;
        }
    }
    va_end(list);
    return length;
}
