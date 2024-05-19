/*
** EPITECH PROJECT, 2022
** my_nbword.c
** File description:
** my_nbword.c
*/

#include "transfer.h"

int my_nbword(const char *str)
{
    int i = 0;
    int div_result = 0;

    while (str[i] != '\0') {
        if (my_issep(str[i]) == 0) {
            div_result = div_result + 1;
        }
        i = i + 1;
    }
    return div_result + 1;
}
