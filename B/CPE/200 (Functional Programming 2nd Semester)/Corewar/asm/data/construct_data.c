/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** constuct_data.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "asm.h"

int create_data(const char *av[], data_t *data)
{
    char **array = NULL;

    if ((array = get_array(av)) == NULL) {
        return 84;
    }
    if (init_structure(array, data) == 84) {
        my_free_array(array);
        return 84;
    }
    my_free_array(array);
    return 0;
}
