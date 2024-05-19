/*
** EPITECH PROJECT, 2022
** my_lenword.c
** File description:
** my_lenword.c
*/

#include "transfer.h"

int my_lenword(const char *str, int i)
{
    int div_result = 0;

    while (my_issep(str[i]) == 1) {
        div_result = div_result + 1;
        i = i + 1;
    }
    return div_result;
}
