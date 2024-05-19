/*
** EPITECH PROJECT, 2022
** my_free.c
** File description:
** my_free.c
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
