/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "lingo.h"

static bool is_valid_word(const char *buffer)
{
    int len_word = 0;

    len_word = my_strlen(buffer);
    if (len_word < 1) {
        return false;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] < 'a' || buffer [i] > 'z') {
            return false;
        }
    }
    return true;
}

int error(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (is_valid_word(array[i]) == false) {
            return 84;
        }
    }
    return 0;
}
