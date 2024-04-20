/*
** EPITECH PROJECT, 2023
** conditions_object.c
** File description:
** conditions_object.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int condition_instructions(body_args *body, int i)
{
    if (body->array[0][my_strlen(body->array[0]) - 1] == ':' &&
    body->array[1] != NULL) {
        if (my_strcmp(body->array[1], op_tab[i].mnemonique) == 0) {
            return i;
        }
    }
    if (my_strcmp(body->array[0], op_tab[i].mnemonique) == 0) {
        return i;
    }
    return -1;
}

void condition_loop_args(body_args *body, int i, data_t *data,
int pos_instruction)
{
    body->args = get_args(body, i, data, pos_instruction);
    body->isIndex = verif_index(body, body->coding_byte);
    if (body->args != NULL && !body->isIndex) {
        body->i_arg = my_atoi(body->args);
        write_args(body, body->fd);
    } else if (body->args != NULL) {
        body->i_arg = my_atoi(body->args);
        write_index(body, body->fd);
    }
    body->index_cb++;
}
