/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-eddy.gardes
** File description:
** prog_size
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

int prog_size(data_t *data)
{
    char **line = NULL;
    int dist = 0;

    for (int i = 0; data->instructions[i] != NULL; i++) {
        line = my_tokarray(data->instructions[i], " \t\n");
        dist += get_size_instruction(line);
        my_free_array(line);
    }
    return dist;
}
