/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** My str is lower
*/

#include "my.h"

static void check_islower(char const *str, int a)
{
    if (str[a] >= 97 && str[a] <= 122) {
    } else {
        return 0;
    }
}

int my_str_islower(char const *str)
{
    int a = 0;

    if (str[0] != '\0') {
        for (a; str[a] != '\0'; a++) {
            check_islower(str, a);
        }
        return 1;
    } else {
        return 1;
    }
}
