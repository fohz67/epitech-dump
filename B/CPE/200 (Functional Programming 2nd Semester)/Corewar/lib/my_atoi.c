/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_atoi.c
*/

#include "lib.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str[i] == '-') {
        neg = -1;
        i++;
    }
    while (str[i] != '\0') {
        nb = nb * 10 + str[i] - 48;
        i++;
    }
    return (nb * neg);
}
