/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** my_pow.c
*/

double my_pow(double base, int exponent)
{
    double div_result = 1;
    int i = 0;

    while (i < exponent) {
        div_result = div_result * base;
        i = i + 1;
    }
    return div_result;
}
