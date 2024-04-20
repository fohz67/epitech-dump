/*
** EPITECH PROJECT, 2022
** my_put_zero.c
** File description:
** My put zero
*/

#include "my.h"

int my_get_zero(double nb)
{
    int result = 0;

    if (nb < 0) {
        nb = - nb;
    }

    while (nb < 1) {
        nb = nb * 10;
        result = result + 1;
    }
    return result;
}
