/*
** EPITECH PROJECT, 2022
** engine.c
** File description:
** engine.c
*/

#include <stdio.h>
#include "my.h"

static int engine_main(char **envcp, char *buffer, int result)
{
    char **cmd = NULL;

    cmd = my_tokarray(buffer, " \t\n");
    if (cmd[0] == NULL) {
        return result;
    }
    if (is_artificial_cmd(cmd[0]) == true) {
        result = execute_artificial(cmd, envcp, buffer, result);
    } else {
        result = execute_real(cmd, envcp);
    }
    free_array(cmd);
    return result;
}

static int engine_multicmd(char **envcp, char *buffer, int result)
{
    char **cmd_separator = NULL;

    cmd_separator = my_tokarray(buffer, ";");
    for (int i = 0; cmd_separator[i] != NULL; i++) {
        result = engine_main(envcp, cmd_separator[i], result);
        free(cmd_separator[i]);
    }
    free(cmd_separator);
    return result;
}

int engine_dispatch(char **envcp, char *buffer, int result)
{
    int size = 0;

    size = size_multi_command(buffer);
    if (size > 0) {
        result = engine_multicmd(envcp, buffer, result);
    } else {
        result = engine_main(envcp, buffer, result);
    }
    return result;
}
