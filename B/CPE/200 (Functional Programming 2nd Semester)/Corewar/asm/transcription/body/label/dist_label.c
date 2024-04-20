/*
** EPITECH PROJECT, 2023
** dist_label.c
** File description:
** dist_label.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

int neg_dist(data_t *data, int pos_instruction, int pos_label)
{
    char **line = NULL;
    int dist = 0;

    for (int i = pos_label; i < pos_instruction; i++) {
        line = my_tokarray(data->instructions[i], " \t\n");
        dist += get_size_instruction(line);
        my_free_array(line);
    }
    return (-dist);
}

int pos_dist(data_t *data, int pos_instruction, int pos_label)
{
    char **line = NULL;
    int dist = 0;

    for (int i = pos_instruction; i < pos_label; i++) {
        line = my_tokarray(data->instructions[i], " \t\n");
        dist += get_size_instruction(line);
        my_free_array(line);
        if (dist == -1)
            return -1;
    }
    return dist;
}
