/*
** EPITECH PROJECT, 2023
** check_object.c
** File description:
** check_object.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int check_verif(int i, body_args *body)
{
    if (body->array[0][my_strlen(body->array[0]) - 1] == ':' &&
    body->array[1] != NULL) {
        body->verif = 1;
        i = 2;
    }
    return i;
}

char *get_args(body_args *body, int i, data_t *data, int pos_instruction)
{
    char *args = NULL, *name_label = NULL, *nbr_label = NULL;
    int index_args = 0;
    int j = 1;

    if ((args = malloc(sizeof(char) *
    (my_strlen(body->array[i]) + 1))) == NULL) return NULL;
    if (my_isnbr(body->array[i]) == true)
        j = 0;
    for (; body->array[i][j] != '\0'; j++) {
        if ((name_label = is_label(body->array[i], j)) != NULL) {
            nbr_label = calc_dist(data, name_label, pos_instruction, body);
            free(name_label);
            free(args);
            return nbr_label;
        }
        args[index_args] = body->array[i][j];
        index_args++;
    }
    args[index_args] = '\0';
    return args;
}

int loop_args(body_args *body, int pos_instruction, data_t *data)
{
    body->isIndex = false;
    body->args = NULL;
    body->verif = 0;
    body->index_cb = 0;
    body->i_arg = 0;
    int i = 1;

    i = check_verif(i, body);
    for (; i != (body->nb_args + 1 + body->verif) &&
    body->array[i] != NULL; i++) {
        condition_loop_args(body, i, data, pos_instruction);
    }
    if (body->args != NULL) {
        free(body->args);
    }
    return 0;
}

void process_args(body_args *body)
{
    int i = 1, index_cb = 0;

    i = check_verif(i, body);
    for (int index = 0; index != 4; index++)
        body->coding_byte[index] = 0;
    for (; i != (body->nb_args + 1 + body->verif) &&
    body->array[i] != NULL; i++) {
        if (body->array[i][0] == 'r') {
            body->coding_byte[index_cb] = 1;
            index_cb++;
        }
        if (body->array[i][0] == '%') {
            body->coding_byte[index_cb] = 2;
            index_cb++;
        }
        if (my_isnbr(body->array[i]) == true) {
            body->coding_byte[index_cb] = 3;
            index_cb++;
        }
    }
}

int check_args(body_args *body, int pos_instruction, int pos_struct,
data_t *data)
{
    body->nb_args = 0;
    body->verif = 0;

    body->nb_args = op_tab[pos_struct].nbr_args + 48;
    process_args(body);
    if (!is_exceptions(body)) {
        get_coding_byte(body, body->fd);
    }
    if (loop_args(body, pos_instruction, data) == 84) {
        return 84;
    }
    return 0;
}
