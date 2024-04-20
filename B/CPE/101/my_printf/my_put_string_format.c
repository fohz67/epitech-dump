/*
** EPITECH PROJECT, 2022
** my_put_string_format.c
** File description:
** My put string format
*/

#include "my.h"

int my_put_string_format(const char *str, const char *format, int index)
{
    int count = 0;

    if (format[index] == '#')
        count = my_put_space(format, index, my_get_string_len(str));

    index = 0;

    while (str[index] != '\0') {
        my_put_char(str[index]);
        index = index + 1;
    }
    return index + count;
}
