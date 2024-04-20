/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** my_pow.c
*/

#include "../include/my.h"

double my_pow(double base, int exponent)
{
    double result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
