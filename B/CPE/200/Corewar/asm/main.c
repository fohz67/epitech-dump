/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "lib.h"
#include "asm.h"

static void free_data(data_t *data, body_args *body)
{
    free(data->name);
    free(data->comment);
    free(data->begin_instruct);
    my_free_array(data->instructions);
    free(data);
    free(body);
}

static int create_progs(int result,const char *av[], data_t *data,
body_args *body)
{
    if ((result = create_data(av, data)) == 84)
        return 84;
    if (check_data_instructions(data) == 84)
        return 84;
    if (fill_struct(data, body, av) == 84)
        return 84;
    return 0;
}

int main(int ac, const char *av[])
{
    data_t *data = NULL;
    body_args *body = NULL;
    int result = 0;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        return help();
    if ((data = malloc(sizeof(data_t))) == NULL)
        return 84;
    if ((body = malloc(sizeof(body_args))) == NULL)
        return 84;
    if (create_progs(result, av, data, body) == 84)
        return 84;
    free_data(data, body);
    return result;
}
