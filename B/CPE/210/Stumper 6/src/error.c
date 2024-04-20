/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "hangman.h"

static bool is_valid_number_of_tries(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

static bool is_valid_word(const char *buffer)
{
    int len_word = 0;

    len_word = my_strlen(buffer);
    if (len_word < 1) {
        return false;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\t') {
            return false;
        }
    }
    return true;
}

int error(int ac, const char *av[], char **array)
{
    if (ac == 3 && is_valid_number_of_tries(av[2]) == false) {
        return 84;
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (is_valid_word(array[i]) == false) {
            return 84;
        }
    }
    return 0;
}
