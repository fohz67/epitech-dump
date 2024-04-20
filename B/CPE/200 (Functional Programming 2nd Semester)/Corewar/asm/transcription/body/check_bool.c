/*
** EPITECH PROJECT, 2023
** check_is_index.c
** File description:
** check_is_index.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

bool verif_index(body_args *body, int *coding_byte)
{
    const char *exceptions[] = {"ldi", "zjmp", "fork", "sti", NULL};

    for (int i = 0; exceptions[i] != NULL; i++) {
        if (my_strncmp(body->array[0], exceptions[i],
        my_strlen(exceptions[i])) == 0 &&
        coding_byte[body->index_cb] != 1) {
            return true;
        }
        if (body->array[1] != NULL &&
        my_strncmp(body->array[1], exceptions[i],
        my_strlen(exceptions[i])) == 0 &&
        coding_byte[body->index_cb] != 1) {
            return true;
        }
    }
    return false;
}

bool is_exceptions(body_args *body)
{
    const char* exceptions[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; exceptions[i] != NULL; i++) {
        if (my_strncmp(body->array[0], exceptions[i],
        my_strlen(exceptions[i])) == 0)
            return true;
        if (body->array[1] != NULL &&
        my_strncmp(body->array[1], exceptions[i],
        my_strlen(exceptions[i])) == 0)
            return true;
    }
    return false;
}
