/*
** EPITECH PROJECT, 2022
** sum_numbers.c
** File description:
** Sum numbers
*/

#include "./includes/bsprintf.h"
#include <stdarg.h>

int sum_numbers(int n, ...)
{
    va_list va_p;
    int num = 0;
    if (n > va_p)
        return 84;
    va_start(va_p, n);
    for (int a = 0; a < n; a++)
        num = num + va_arg(va_p, int);
    va_end(va_p);
    return num;
}
