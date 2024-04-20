/*
** EPITECH PROJECT, 2022
** my_free_array.c
** File description:
** my_free_array.c
*/

#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

void my_free_intarray(int **array)
{
    for (int i = 0; i < 1000; i++) {
        free(array[i]);
    }
    free(array);
}
