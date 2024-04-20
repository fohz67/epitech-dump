/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** data_validation.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "asm.h"

static bool is_valid_chars(char **temp_array)
{
    int len = 0;

    if (temp_array[0] == NULL) {
        return false;
    }
    len = my_strlen(temp_array[0]);
    for (int i = 0; i < len - 1; i++) {
        if (((temp_array[0][i] >= 'a' && temp_array[0][i] <= 'z') ||
            (temp_array[0][i] >= 'A' && temp_array[0][i] <= 'Z') ||
            (temp_array[0][i] >= '0' && temp_array[0][i] <= '9') ||
            temp_array[0][i] == '_') && temp_array[0][len - 1] == ':') {
                return true;
            }
    }
    return false;
}

bool is_valid_instruction(char *buffer)
{
    char **temp_array = NULL;
    bool result = false;

    if ((temp_array = my_tokarray(buffer, "\n\t ")) == NULL) {
        return false;
    }
    result = is_valid_chars(temp_array);
    my_free_array(temp_array);
    return result;
}
