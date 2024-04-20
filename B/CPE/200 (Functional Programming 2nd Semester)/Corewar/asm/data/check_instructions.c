/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** check_instructions.c
*/

#include <stdlib.h>
#include "lib.h"
#include "asm.h"
#include "op.h"

int validation_args(char *name, char **array, int max_args,
int begin_instruct)
{
    if (my_strcmp(name, "add") == 0 ||
        my_strcmp(name, "sub") == 0 ||
        my_strcmp(name, "aff") == 0)
        if (condition_full_reg(array, max_args + begin_instruct,
        begin_instruct) == 84)
            return 84;
    if (my_strcmp(name, "live") == 0 ||
        my_strcmp(name, "zjmp") == 0 ||
        my_strcmp(name, "fork") == 0 ||
        my_strcmp(name, "lfork") == 0)
        if (condition_full_dir(array, max_args + begin_instruct,
        begin_instruct) == 84)
            return 84;
    return 0;
}

static int validation_number_of_args(char **array, int begin_instruct)
{
    int actual_args = 0;
    int needed_args = 0;

    for (int i = 0; i < 16; i++)
        if (my_strcmp(op_tab[i].mnemonique, array[begin_instruct]) == 0) {
            needed_args = op_tab[i].nbr_args;
            break;
        }
    for (; array[actual_args] != NULL; actual_args++);
    if (actual_args - begin_instruct - 1 != needed_args)
        return 84;
    if (validation_args(array[begin_instruct], array, needed_args,
    begin_instruct) == 84)
        return 84;
    return 0;
}

static int validation_instruction(data_t *data, char *line, int i)
{
    int result = 0;
    int begin_instruct = 0;
    char **array = NULL;

    if ((array = my_tokarray(line, " \t\n")) == NULL)
        return 84;
    if (data->begin_instruct[i] == false)
        begin_instruct = 1;
    if (begin_instruct == 1 && array[begin_instruct] == NULL)
        return 0;
    result = validation_number_of_args(array, begin_instruct);
    my_free_array(array);
    return result;
}

int check_data_instructions(data_t *data)
{
    char *line = NULL;

    for (int i = 0; data->instructions[i] != NULL; i++) {
        if ((line = my_strdup(data->instructions[i])) == NULL)
            return 84;
        if (validation_instruction(data, line, i) == 84) {
            free(line);
            return 84;
        }
        free(line);
        line = NULL;
    }
    return 0;
}
