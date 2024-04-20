/*
** EPITECH PROJECT, 2022
** my_getsize_array.c
** File description:
** my_getsize_array.c
*/

#include <stdlib.h>
#include "my.h"

int my_getsize_lines_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        i++;
    }
    return i;
}

int my_getsize_array(char **array)
{
    int i = 0;
    int size = 0;

    while (array[i] != NULL) {
        size = size + my_strlen(array[i]) + 1;
        i++;
    }
    return size;
}
