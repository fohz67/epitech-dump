/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** My str capitalize
*/

#include "my.h"

static char check_all(char *str, int a)
{
    if (str[a - 1] < 48 || str[a - 1] == '-') {
        str[a] = str[a] - 32;
        return;
    }

    if (str[a - 1] > 59 && str[a - 1] < 65) {
        str[a] = str[a] - 32;
        return;
    }

    if (str[a - 1] > 90 && str[a - 1] < 97) {
        str[a] = str[a] - 32;
        return;
    }

    if (str[a - 1] > 122) {
        str[a] = str[a] - 32;
        return;
    }
}

char *my_strcapitalize(char *str)
{
    int a = 0;

    if (str[0] == '\0')
        return;
    while (str[a] != '\0') {
        if (str[a] >= 65 && str[a] <= 90)
            str[a] = str[a] + 32;
        a = a + 1;
    }
    a = 0;

    while (str[a] != '\0') {
        if (str[a] >= 97 && str[a] <= 122)
            check_all(str, a);
        a = a + 1;
    }
    return str;
}
