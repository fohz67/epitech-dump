/*
** EPITECH PROJECT, 2023
** pipes.c
** File description:
** pipes.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

static void last_pipe_output(char **envcp, char **config, char *buffer, int *fd)
{
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        fd[5] = 1;
        return;
    }
    fd[1] = pipe_fd[1];
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '>' || buffer[i] == '<') {
            my_puterror("Ambiguous output redirect.\n");
            fd[5] = 1;
            return;
        }
    }
    engine_main(envcp, config, buffer, fd);
    if (close(pipe_fd[1]) == -1) {
        fd[5] = 1;
        return;
    }
    fd[0] = pipe_fd[0];
}

static void check_pipe_position(char **cmd_pipes, char **config, char **envcp,
int *fd)
{
    int nb_cmd = 0;

    nb_cmd = my_getsize_lines_array(cmd_pipes);
    if (fd[2] != nb_cmd - 1) {
        last_pipe_output(envcp, config, cmd_pipes[fd[2]], fd);
        if (fd[5] == 1) {
            return;
        }
    } else {
        fd[1] = STDOUT_FILENO;
        fd[5] = controller_redirection(envcp, config, cmd_pipes[fd[2]], fd);
    }
}

int controller_pipe(char **envcp, char **config, char *buffer, int result)
{
    int fd[7] = {STDIN_FILENO, 0, 0, 0, 0, result, 0};
    char **cmd_pipes = NULL;

    if ((cmd_pipes = my_tokarray(buffer, "|\n")) == NULL) {
        return 1;
    }
    fd[3] = my_getsize_lines_array(cmd_pipes);
    fd[5] = result;
    for (int i = 0; i < fd[3]; i++) {
        fd[2] = i;
        check_pipe_position(cmd_pipes, config, envcp, fd);
        if (fd[5] == 1) {
            free_array(cmd_pipes);
            return fd[5];
        }
    }
    free_array(cmd_pipes);
    return fd[5];
}
