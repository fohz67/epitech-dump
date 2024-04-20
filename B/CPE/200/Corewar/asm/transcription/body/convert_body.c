/*
** EPITECH PROJECT, 2023
** convert_body.c
** File description:
** convert_body.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int convert_body_into_binary(data_t *data, body_args *body, int fd)
{
    int pos_struct = 0;
    label_t *label = NULL;
    body->array = NULL;

    label = create_list_label(label, data);
    body->label = label;
    body->fd = fd;
    for (int i = 0; data->instructions[i] != NULL; i++) {
        body->array = my_tokarray(data->instructions[i], ", \n\t");
        pos_struct = check_instructions(body, fd);
        if (pos_struct != -1)
            check_args(body, i, pos_struct, data);
        my_free_array(body->array);
    }
    free_label(label);
    return 0;
}
