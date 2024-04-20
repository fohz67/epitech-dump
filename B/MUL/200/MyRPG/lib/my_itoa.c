/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** my_itoa.c
*/

#include <stdlib.h>
#include "lib.h"

char *my_reverse(char *buffer, int i, int j)
{
    while (i < j) {
        my_swap(&buffer[i++], &buffer[j--]);
    }
    return buffer;
}

static int my_itoa2(int i, int value, int base, char *buffer)
{
    if (i == 0) {
        buffer[i++] = '0';
    }
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
    return i;
}

char* my_itoa(int value, int base)
{
    int i = 0;
    int nb = value;
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * (my_nbrlen(value) + 1));
    while (nb) {
        int mod = nb % base;
        if (mod >= 10) {
            buffer[i++] = 65 + (mod - 10);
        } else {
            buffer[i++] = 48 + mod;
        }
        nb = nb / base;
    }
    i = my_itoa2(i, value, base, buffer);
    buffer[i] = '\0';
    return my_reverse(buffer, 0, i - 1);
}
