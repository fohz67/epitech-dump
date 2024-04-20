/*
** EPITECH PROJECT, 2022
** my_putarray.c
** File description:
** my_putarray.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void my_putarray(char **array)
{
    int index = 0;

    while (array[index] != NULL) {
        printf("%s", array[index]);
        if (array[index + 1] != NULL) {
            printf("\n");
        }
        index = index + 1;
    }
}
