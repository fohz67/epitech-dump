/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** construct_structure.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

int init_instructions(char **array, data_t *data)
{
    int it = 0;
    int size = 0;

    size = my_getsize_array(array);
    if ((data->begin_instruct = malloc(sizeof(bool) * size)) == NULL)
        return 84;
    if ((data->instructions = malloc(sizeof(char *) * (size + 1))) == NULL)
        return 84;
    for (int i = 0; array[i] != NULL; i++)
        data->begin_instruct[i] = false;
    for (int i = 2; array[i] != NULL; i++) {
        data->instructions[it] = retrieve_instructions(array[i], data, it);
        if (data->instructions[it] == NULL)
            return 84;
        it++;
    }
    data->instructions[it] = NULL;
    return 0;
}

int init_structure(char **array, data_t *data)
{
    int result = 0;

    if ((data->name = retrieve_data(array, ".name ")) == NULL)
        return 84;
    data->comment = retrieve_data(array, ".comment ");
    if ((result = init_instructions(array, data)) == 84)
        return 84;
    if (data->comment == NULL && array[2] != NULL)
        return 84;
    if (data->comment != NULL && array[2] != NULL)
        return 0;
    if (data->comment == NULL && array[2] == NULL)
        return 0;
    if (data->comment != NULL && array[2] == NULL)
        return 0;
    return 0;
}
