/*
** EPITECH PROJECT, 2023
** get_label.c
** File description:
** get_label.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

int get_size_instruction(char **line)
{
    int index = 1;
    int size = 0;
    char *instruction = NULL;

    for (int i = 0; line[0][i] != '\0'; i++) {
        if (line[0][i] == ':' && line[1] != NULL) {
            instruction = my_strdup(line[1]);
            index = 2;
        }
    }
    if (instruction == NULL && line[1] != NULL)
        instruction = my_strdup(line[0]);
    if (instruction == NULL)
        return 0;
    for (; line[index] != NULL; index++)
        size += calc_size_instruction(instruction, line[index]);
    if (verif_conding_byte(instruction) == 0)
        size += 1;
    free(instruction);
    return size + 1;
}

int get_pos_label(label_t *label, char *name_label)
{
    label_t *tmp = label;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->name != NULL && name_label != NULL &&
        my_strcmp(tmp->name, name_label) == 0)
            return tmp->pos;
    }
    return -1;
}

char *get_name_label(char *str, int j)
{
    char *name_label = NULL;
    int index = 0;

    j++;
    if ((name_label = malloc(sizeof(char) * my_strlen(str))) == NULL)
        return NULL;
    for (; str[j] != '\0'; j++) {
        name_label[index] = str[j];
        index++;
    }
    name_label[index] = '\0';
    return name_label;
}
