/*
** EPITECH PROJECT, 2022
** my_nbword.c
** File description:
** my_nbword.c
*/

#include "../include/my.h"

int my_nbword(const char *str)
{
    int i = 0;
    int result = 0;

    i = my_skipsep(str, i);
    while (str[i] != '\0') {
        if (my_issep(str[i]) == 0 && str[i + 1] != '\0' &&
        my_issep(str[i + 1]) == 1) {
            result = result + 1;
        }
        i = i + 1;
    }
    return result + 1;
}
