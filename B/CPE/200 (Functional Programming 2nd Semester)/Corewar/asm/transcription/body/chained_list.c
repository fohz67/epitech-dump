/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** chained_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

static label_t *add_label(label_t *label, char *name, int pos)
{
    label_t *new = NULL;
    label_t *tmp = label;

    if ((new = malloc(sizeof(label_t))) == NULL)
        return NULL;
    new->name = NULL;
    new->next = NULL;
    if ((new->name = malloc(sizeof(char) * my_strlen(name))) == NULL)
        return NULL;
    for (int i = 0; i < my_strlen(name) - 1; i++)
        new->name[i] = name[i];
    new->name[my_strlen(name) - 1] = '\0';
    new->pos = pos;
    if (label == NULL)
        return new;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return label;
}

static  label_t *check_label(char** line, int i, label_t *label)
{
    if (line[0] != NULL && line[0][my_strlen(line[0]) - 1] == ':') {
        if ((label = add_label(label, line[0], i)) == NULL)
            return label;
    }
    return label;
}

void free_label(label_t *label)
{
    label_t *tmp = label;

    while (label != NULL) {
        tmp = label;
        label = label->next;
        free(tmp->name);
        free(tmp);
    }
}

label_t *create_list_label(label_t *label, data_t *data)
{
    char **line = NULL;

    for (int i = 0; data->instructions[i] != NULL; i++) {
        line = my_tokarray(data->instructions[i], " \t\n");
        label = check_label(line, i, label);
        my_free_array(line);
    }
    return label;
}
