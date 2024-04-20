/*
** EPITECH PROJECT, 2022
** my_nbrlen.c
** File description:
** my_nbrlen.c
*/

#include "../include/my.h"

int my_nbrlen(long int nb)
{
    long power = 1;
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        count = count + 1;
    }
    while (nb / power > 9) {
        power = power * 10;
    }
    while (power >= 1) {
        power = power / 10;
        count = count + 1;
    }
    return count;
}
