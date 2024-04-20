/*
** EPITECH PROJECT, 2022
** my_lenword.c
** File description:
** my_lenword.c
*/

#include "generator.h"

int my_lenword(const char *str, int i)
{
    int result = 0;

    while (my_issep(str[i]) == 1) {
        result = result + 1;
        i = i + 1;
    }
    return result;
}
