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
    int i = 0;

    while (i < exponent) {
        result = result * base;
        i = i + 1;
    }
    return result;
}
