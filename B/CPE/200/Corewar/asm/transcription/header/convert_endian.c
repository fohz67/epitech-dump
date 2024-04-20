/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** convert_endian.c
*/

#include <stddef.h>

int convert_big_endian_int(int little_endian)
{
    int big_endian = 0;

    big_endian = ((little_endian & 0xFF) << 24) |
    ((little_endian & 0xFF00) << 8) |
    ((little_endian & 0xFF0000) >> 8) |
    ((little_endian & 0xFF000000) >> 24);
    return big_endian;
}

short convert_big_endian_short(short value)
{
    unsigned char *ptr = NULL;
    unsigned char temp = 0;

    ptr = (unsigned char *)&value;
    temp = ptr[0];
    ptr[0] = ptr[1];
    ptr[1] = temp;

    return value;
}
