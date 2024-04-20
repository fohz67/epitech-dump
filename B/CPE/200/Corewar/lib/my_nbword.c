/*
** EPITECH PROJECT, 2023
** my_nbword.c
** File description:
** my_nbword.c
*/

#include "lib.h"

int my_nbword(const char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        if (my_issep(str[i]) == 0) {
            result = result + 1;
        }
        i = i + 1;
    }
    return result + 1;
}
