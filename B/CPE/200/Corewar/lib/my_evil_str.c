/*
** EPITECH PROJECT, 2022
** my_evil_str.c
** File description:
** task4
*/

#include "lib.h"

char *my_evil_str(char *str)
{
    int a = 0;
    int b = 0;
    char c;

    b = my_strlen(str) - 1;
    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a = a + 1;
        b = b - 1;
    }
    return (str);
}
