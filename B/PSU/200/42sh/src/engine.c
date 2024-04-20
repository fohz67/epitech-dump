/*
** EPITECH PROJECT, 2023
** engine.c
** File description:
** engine.c
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

static int update_redirect(int redirection, char **cmd, int *i)
{
    for (; cmd[*i] != NULL; (*i)++) {
        if (my_strcmp(cmd[*i], ">") == 0) {
            redirection++;
            break;
        }
        if (my_strcmp(cmd[*i], ">>") == 0) {
            redirection++;
            break;
        }
        if (my_strcmp(cmd[*i], "<") == 0) {
            redirection++;
            break;
        }
        if (my_strcmp(cmd[*i], "<<") == 0) {
            redirection++;
            break;
        }
    }
    return redirection;
}

static void update_output(char **cmd)
{
    int redirection = 0;
    int i = 0;

    redirection = update_redirect(redirection, cmd, &i);
    if (redirection == 0) {
        return;
    }
    for (; cmd[i + 2] != NULL; i++) {
        free(cmd[i]);
        cmd[i] = my_strdup(cmd[i + 2]);
    }
    cmd[i] = NULL;
}

void engine_main(char **envcp, char **config, char *buffer, int *fd)
{
    char **cmd = NULL;

    if ((cmd = my_tokarray(buffer, " \t\n")) == NULL) {
        fd[5] = 1;
        return;
    }
    update_output(cmd);
    if (cmd[0] == NULL) {
        fd[5] = 1;
        return;
    }
    if (is_artificial_cmd(cmd[0]) == true) {
        if (fd[3] > 1 || fd[4] == 1 || fd[6] == 1) {
            fd[5] = 0;
            exec_pipe_builtin(cmd, envcp, buffer, fd);
        } else
            execute_artificial(cmd, envcp, buffer, fd);
    } else
        execute_real(cmd, config, envcp, fd);
    free_array(cmd);
}
