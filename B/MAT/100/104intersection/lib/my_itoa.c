/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** my_itoa.c
*/

#include "../include/my.h"

void my_swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

char* my_reverse(char *buffer, int i, int j)
{
    while (i < j)
        my_swap(&buffer[i++], &buffer[j--]);
    return buffer;
}

char* my_itoa(int value, char* buffer, int base)
{
    int n = value < 0 ? - value : value;
    int i = 0;

    if (base < 2 || base > 32)
        return buffer;
    while (n) {
        int r = n % base;
        if (r >= 10)
            buffer[i++] = 65 + (r - 10);
        else
            buffer[i++] = 48 + r;
        n = n / base;
    }
    if (i == 0)
        buffer[i++] = '0';
    if (value < 0 && base == 10)
        buffer[i++] = '-';

    buffer[i] = '\0';
    return my_reverse(buffer, 0, i - 1);
}
