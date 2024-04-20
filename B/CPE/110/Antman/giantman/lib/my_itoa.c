/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** my_itoa.c
*/

#include "../include/my.h"

char *my_reverse(char *buffer, int i, int j)
{
    while (i < j) {
        my_swap(&buffer[i++], &buffer[j--]);
    }
    return buffer;
}

char* my_itoa(int value, int base)
{
    char *buffer = malloc(my_nbrlen(value));
    int nbr = my_abs(value);
    int i = 0;
    if (base < 2 || base > 32)
        return buffer;
    while (nbr) {
        int mod = nbr % base;
        if (mod >= 10)
            buffer[i++] = 65 + (mod - 10);
        else
            buffer[i++] = 48 + mod;
        nbr = nbr / base;
    }
    if (i == 0)
        buffer[i++] = '0';
    if (value < 0 && base == 10)
        buffer[i++] = '-';

    buffer[i] = '\0';
    return my_reverse(buffer, 0, i - 1);
}
