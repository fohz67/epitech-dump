/*
** EPITECH PROJECT, 2022
** my_get_digit.c
** File description:
** My get digit
*/

#include "my.h"

int my_get_digit(const char *format, int index, char c)
{
    int digit = 0, length = 0;
    char str[64] = {0};

    if (format[index] == '#') {
        while (format[index] != '.' && format[index] != c && *format != '\0')
            index = index + 1;
        if (format[index] == c) {
            return 6;
        } else {
            index = index + 1;
        }
    } else {
        index = index + 2;
    }

    while (my_get_alpha(format[index]) == 0)
        str[length++] = format[index++];

    digit = my_get_int(str);
    return digit;
}
