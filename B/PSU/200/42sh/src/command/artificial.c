/*
** EPITECH PROJECT, 2023
** artificial.c
** File description:
** artificial.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

int execute_artificial(char **cmd, char **envcp, char *buffer, int *fd)
{
    static const char *all_cmds[] = {"cd", "env", "exit", "setenv",
    "unsetenv", "echo"};

    if (my_strcmp(cmd[0], all_cmds[0]) == 0)
        fd[5] = my_cd(cmd, envcp);
    if (my_strcmp(cmd[0], all_cmds[1]) == 0)
        fd[5] = my_env(envcp);
    if (my_strcmp(cmd[0], all_cmds[2]) == 0)
        fd[5] = my_exit(cmd, envcp, buffer, fd[5]);
    if (my_strcmp(cmd[0], all_cmds[3]) == 0)
        fd[5] = my_setenv(cmd, envcp, NULL, NULL);
    if (my_strcmp(cmd[0], all_cmds[4]) == 0)
        fd[5] = my_unsetenv(cmd, envcp);
    if (my_strcmp(cmd[0], all_cmds[5]) == 0)
        fd[5] = my_echo(cmd, fd[5], envcp);
    if (my_strncmp("\\", cmd[0], 1) == 0)
        fd[5] = my_inibitors(fd[5], envcp, cmd);
    return fd[5];
}

static int execute_verif(char **cmd, char **envcp, char *buffer, int *fd)
{
    if (execute_pipe(fd) == 1) {
        return 1;
    }
    if ((execute_artificial(cmd, envcp, buffer, fd)) == 1) {
        return 1;
    }
    return 0;
}

void exec_pipe_builtin(char **cmd, char **envcp, char *buffer, int *fd)
{
    int status = 0;
    pid_t pid_child = 0;

    pid_child = fork();
    if (pid_child == 0) {
        if (execute_verif(cmd, envcp, buffer, fd) == 1) {
            fd[5] = 1;
        }
        exit(fd[5]);
    }
    if (pid_child > 0) {
        if (fd[2] == fd[3] - 1) {
            waitpid(pid_child, &status, 0);
            fd[5] = segfault(status);
        }
    }
}
