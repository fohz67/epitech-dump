/*
** EPITECH PROJECT, 2023
** hard_fractals.c
** File description:
** hard_fractals.c
*/

#include <stddef.h>
#include "my.h"

int hard_fractals(char *first_pattern, char *second_pattern, int size)
{
    char **pattern1 = NULL;
    char **pattern2 = NULL;

    pattern1 = my_str_to_word_array(first_pattern);
    pattern2 = my_str_to_word_array(second_pattern);

    if (pattern1 == NULL || pattern2 == NULL) {
        return 84;
    }
    return 0;
}
