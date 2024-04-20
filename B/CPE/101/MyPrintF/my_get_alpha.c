/*
** EPITECH PROJECT, 2022
** my_get_alpha.c
** File description:
** My get alpha
*/

#include "my.h"

int my_get_alpha(char c)
{
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}
