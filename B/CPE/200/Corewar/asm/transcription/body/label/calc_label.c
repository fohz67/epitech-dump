/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** label.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

int calc_size_instruction(char *instruction, char *arg)
{
    int size = 0;

    if (arg[0] == 'r')
        size += 1;
    if (arg[0] == '%' && is_index(instruction) == 0)
        size += 4;
    if ((arg[0] >= '0' && arg[0] <= '9') || (is_index(instruction) == 1 &&
    arg[0] != 'r'))
        size += 2;
    return size;
}

char *calc_dist(data_t *data, char *name_label, int pos_instruction,
body_args *body)
{
    int pos_label = 0;
    int neg = 0;
    int dist = 0;
    char *nbr_label = NULL;

    pos_label = get_pos_label(body->label, name_label);
    if (pos_label == -1)
        return NULL;
    neg = pos_label - pos_instruction;
    if (neg > 0)
        dist = pos_dist(data, pos_instruction, pos_label);
    else
        dist = neg_dist(data, pos_instruction, pos_label);
    if (dist == -1)
        return NULL;
    return modif_itoa(dist, nbr_label);
}
