/*
** EPITECH PROJECT, 2022
** itoa.c
** File description:
** itoa.c
*/

#include "./include/my.h"

void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

char* reverse(char *buffer, int i, int j)
{
    while (i < j)
        swap(&buffer[i++], &buffer[j--]);
    return buffer;
}

char* itos(int value, char* buffer, int base)
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
    return reverse(buffer, 0, i - 1);
}
