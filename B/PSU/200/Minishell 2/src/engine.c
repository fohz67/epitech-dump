/*
** EPITECH PROJECT, 2022
** engine.c
** File description:
** engine.c
*/

#include <stdio.h>
#include "my.h"

static void update_output(char **cmd)
{
    int i = 0;
    int redirection = 0;

    for (; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], ">") == 0) {
            redirection++;
            break;
        }
    }
    if (redirection == 0) {
        return;
    }
    for (; cmd[i + 2] != NULL; i++) {
        free(cmd[i]);
        cmd[i] = my_strdup(cmd[i + 2]);
    }
    cmd[i] = NULL;
}

int engine_main(char **envcp, char *buffer, int result, int *fd)
{
    char **cmd = NULL;

    cmd = my_tokarray(buffer, " \t\n");
    update_output(cmd);
    if (cmd != NULL && cmd[0] != NULL) {
        if (is_artificial_cmd(cmd[0]) == true) {
            result = execute_artificial(cmd, envcp, buffer, result);
        } else {
            result = execute_real(cmd, envcp, fd);
        }
        free_array(cmd);
    } else {
        result = 1;
    }
    return result;
}
