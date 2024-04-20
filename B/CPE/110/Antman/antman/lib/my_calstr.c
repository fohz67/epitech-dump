/*
** EPITECH PROJECT, 2022
** my_calstr.c
** File description:
** my_calstr.c
*/

#include "../include/my.h"

int my_lenword(const char *str, int i)
{
    int result = 0;

    while (my_issep(str[i]) == 0) {
        result = result + 1;
        i = i + 1;
    }
    return result;
}

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

int my_nbline(const char *str)
{
    int i = 0;
    int result = 0;
    char nb[64] = {0};

    while (str[i] >= '0' && str[i] <= '9') {
        nb[i] = str[i];
        i = i + 1;
    }
    result = my_getnbr(nb);
    return result;
}
