/*
** EPITECH PROJECT, 2022
** my_skipsep.c
** File description:
** my_skipsep.c
*/

#include "solver.h"

int my_skipsep(const char *str,  int i)
{
    while (str[i] != '\0' && my_issep(str[i]) == 0) {
        i = i + 1;
    }
    return i;
}
