/*
** EPITECH PROJECT, 2023
** and_separators.c
** File description:
** and_separators.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int controller_and_separators(char **envcp, char **config, char *buffer,
int result)
{
    char **cmd_and_separator = NULL;

    if ((cmd_and_separator = my_tokarray(buffer, "&\n")) == NULL) {
        return 1;
    }
    for (int i = 0; cmd_and_separator[i] != NULL; i++) {
        result = controller_pipe(envcp, config, cmd_and_separator[i], result);
        if (result != 0) {
            free_array(cmd_and_separator);
            return result;
        }
    }
    free_array(cmd_and_separator);
    return result;
}
