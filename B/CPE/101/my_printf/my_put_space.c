/*
** EPITECH PROJECT, 2022
** my_put_space.c
** File description:
** My put space
*/

#include "my.h"

int my_put_space(const char *format, int index, int len)
{
    char str[64] = {0};
    int length = 0, nbr = 0;

    index = index + 1;

    while (my_get_alpha(format[index]) == 0)
        str[length++] = format[index++];

    length = 0;
    nbr = my_get_int(str);

    while (nbr - len > 0) {
        length = length + my_put_char(' ');
        nbr = nbr - 1;
    }
    return length;
}
