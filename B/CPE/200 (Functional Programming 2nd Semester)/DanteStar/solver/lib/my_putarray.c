/*
** EPITECH PROJECT, 2022
** my_putarray.c
** File description:
** my_putarray.c
*/

#include <stdlib.h>
#include "solver.h"

void my_putarray(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        my_putstr(array[i]);
        if (array[i + 1] != NULL) {
            my_putchar('\n');
        }
        i = i + 1;
    }
}
