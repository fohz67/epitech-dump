/*
** EPITECH PROJECT, 2022
** sum_string_length.c
** File description:
** Sum string length
*/

#include "./includes/bsprintf.h"
#include <stdarg.h>

int sum_strings_length(int n, ...)
{
    va_list va_p;
    int num = 0;

    if (n > va_p)
        return 84;
    va_start(va_p, n);
    for (int a = 0; a < n; a++)
        num = num + my_strlen(va_arg(va_p, char*));
    va_end(va_p);
    return num;
}
