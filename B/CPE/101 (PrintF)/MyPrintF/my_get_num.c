/*
** EPITECH PROJECT, 2022
** my_get_num.c
** File description:
** My get num
*/

#include "my.h"

int my_get_num(char c)
{
    if (c >= 48 && c <= 59) {
        return 1;
    } else {
        return 0;
    }
}
