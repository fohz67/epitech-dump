/*
** EPITECH PROJECT, 2023
** and_separators.c
** File description:
** and_separators.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int controller_or_separators(char **envcp, char **config, char *buffer,
int result)
{
    char **cmd_or_separator = NULL;

    if ((cmd_or_separator = my_tokarray_duo(buffer, "|")) == NULL) {
        return 1;
    }
    for (int i = 0; cmd_or_separator[i] != NULL; i++) {
        result = controller_and_separators(envcp, config,
        cmd_or_separator[i], result);
        if (result == 0) {
            free_array(cmd_or_separator);
            return result;
        }
    }
    free_array(cmd_or_separator);
    return result;
}
