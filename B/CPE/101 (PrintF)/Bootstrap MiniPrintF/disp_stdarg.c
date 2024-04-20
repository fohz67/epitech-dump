/*
** EPITECH PROJECT, 2022
** disp_strarg.c
** File description:
** Display strdargs
*/

#include "./includes/bsprintf.h"
#include <stdarg.h>

void disp_stdarg(char *s, ...)
{
    va_list va_p;

    va_start(va_p, s);
    for (int a = 0; s[a] != '\0'; a++) {
        if (s[a] == 's')
            my_putstr(va_arg(va_p, char*));
        if (s[a] == 'c')
            my_putchar(va_arg(va_p, char));
        if (s[a] == 'i')
            my_put_nbr(va_arg(va_p, int));
        my_putchar('\n');
    }
    va_end(va_p);
}
