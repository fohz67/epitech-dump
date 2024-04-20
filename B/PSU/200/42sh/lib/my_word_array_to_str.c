/*
** EPITECH PROJECT, 2023
** my_word_array_to_str.c
** File description:
** my_word_array_to_str.c
*/

#include <stdlib.h>
#include "my.h"

static void loop_word_array_to_str(char **array, char *buffer)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (array[i] != NULL) {
        while (array[i][j] != '\0') {
            buffer[k] = array[i][j];
            j++;
            k++;
        }
        i++;
        j = 0;
        buffer[k] = ' ';
        k++;
    }
    buffer[k] = '\0';
}

char *my_word_array_to_str(char **array)
{
    char *buffer = NULL;

    buffer = malloc(sizeof(char) *(my_getsize_array(array) + 1));
    if (buffer == NULL) {
        return NULL;
    }
    loop_word_array_to_str(array, buffer);
    return buffer;
}
