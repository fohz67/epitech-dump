/*
** EPITECH PROJECT, 2022
** my_get_nbrpower.c
** File description:
** My get nbr power
*/

#include "my.h"

long long int my_get_power(int digit)
{
    long long int power = 1;

    if (digit == 1)
        return 1;

    while (digit-- > 0)
        power = power * 10;

    return power;
}
