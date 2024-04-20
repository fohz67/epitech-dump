/*
** EPITECH PROJECT, 2022
** engine.c
** File description:
** engine.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

static int controller_pipe3(char **envcp, char *buffer, int *fd, int *pipe_fd)
{
    int result = 0;

    if (pipe(pipe_fd) == -1) {
        return 1;
    }
    fd[1] = pipe_fd[1];
    result = controller_redirection(envcp, buffer, result, fd);
    if (close(pipe_fd[1]) == -1) {
        return 1;
    }
    fd[0] = pipe_fd[0];
    return result;
}

static int controller_pipe2(char **cmd_pipes, char **envcp, int *fd, int i)
{
    int result = 0;
    int nb_cmd = 0;
    int pipe_fd[2];

    nb_cmd = my_getsize_lines_array(cmd_pipes);
    if (my_strlen(cmd_pipes[i]) <= 1) {
        my_puterror("Invalid null command.\n");
        return 1;
    }
    if (i != nb_cmd - 1) {
        if (controller_pipe3(envcp, cmd_pipes[i], fd, pipe_fd) == 1) {
            return 1;
        }
    } else {
        fd[1] = STDOUT_FILENO;
        result = controller_redirection(envcp, cmd_pipes[i], result, fd);
    }
    return result;
}

static int controller_pipe(char **envcp, char *buffer, int result)
{
    int nb_cmd = 0;
    int fd[4] = {STDIN_FILENO, 0, 0, 0};
    char **cmd_pipes = NULL;

    cmd_pipes = my_tokarray(buffer, "|\n");
    if (cmd_pipes == NULL) {
        return 1;
    }
    nb_cmd = my_getsize_lines_array(cmd_pipes);
    fd[3] = nb_cmd;
    for (int i = 0; i < nb_cmd; i++) {
        fd[2] = i;
        if (controller_pipe2(cmd_pipes, envcp, fd, i) == 1) {
            break;
        }
    }
    free_array(cmd_pipes);
    return result;
}

int controller_separators(char **envcp, char *buffer, int result)
{
    char **cmd_separator = NULL;

    cmd_separator = my_tokarray(buffer, ";\n");
    if (cmd_separator != NULL) {
        for (int i = 0; cmd_separator[i] != NULL; i++) {
            result = controller_pipe(envcp, cmd_separator[i], result);
        }
        free_array(cmd_separator);
    } else {
        result = 1;
    }
    return result;
}
