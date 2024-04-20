/*
** EPITECH PROJECT, 2022
** my_put_f.c
** File description:
** My put f
*/

#include "my.h"

int my_get_double_len(int before, int param)
{
    int length = 0;

    length = length + my_get_int_len(before);
    length = length + 1;
    length = length + param;

    return length;
}
