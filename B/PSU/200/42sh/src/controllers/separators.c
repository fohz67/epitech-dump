/*
** EPITECH PROJECT, 2023
** separators.c
** File description:
** separators.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int controller_separators(char **envcp, char **config, char *buffer, int result)
{
    char **cmd_separator = NULL;

    if ((cmd_separator = my_tokarray(buffer, ";\n")) == NULL) {
        return 1;
    }
    for (int i = 0; cmd_separator[i] != NULL; i++) {
        result = controller_or_separators(envcp, config, cmd_separator[i],
        result);
    }
    free_array(cmd_separator);
    return result;
}
