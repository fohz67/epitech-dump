/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** data_retrieving.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "asm.h"
#include "op.h"

char *retrieve_instructions(char *buffer, data_t *data, int j)
{
    char *str = NULL;

    if (is_valid_instruction(buffer) == true) {
            data->begin_instruct[j] = false;
            str = my_strdup(buffer);
            return str;
    }
    for (int i = 0; i < 16; i++) {
        if (my_strncmp(op_tab[i].mnemonique, buffer,
        my_strlen(op_tab[i].mnemonique)) == 0) {
            data->begin_instruct[j] = true;
            str = my_strdup(buffer);
            return str;
        }
    }
    return NULL;
}

char *retrieve_data(char **array, char *name)
{
    char *str = NULL;
    int len = 0;
    int nb = 0;

    len = my_strlen(name);
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strncmp(name, array[i], len) == 0) {
            str = my_stridup(array[i], len);
            nb++;
        }
    }
    if (nb != 1) {
        free(str);
        return NULL;
    }
    str = my_str_cleaner(str, "\"\t\n");
    return str;
}
