/*
** EPITECH PROJECT, 2023
** real.c
** File description:
** real.c
*/

#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include "scripting.h"
#include "my.h"

static char **alias_valid(char **config, char *cmd)
{
    char **alias = NULL;
    char **configcp = NULL;

    if (config == NULL)
        return NULL;
    configcp = copy_env((const char **)config);
    alias = get_alias(configcp, cmd);
    if (alias == NULL) {
        free_array(configcp);
        return NULL;
    }
    free_array(configcp);
    return alias;
}

int execute_pipe(int *fd)
{
    int result = 0;

    if (fd[0] != STDIN_FILENO) {
        if (dup2(fd[0], STDIN_FILENO) == -1)
            return 1;
        if (close(fd[0]) == -1)
            return 1;
    }
    if (fd[1] != STDOUT_FILENO) {
        if (dup2(fd[1], STDOUT_FILENO) == -1)
            return 1;
        if (close(fd[1]) == -1)
            return 1;
    }
    return result;
}

static int execute_verif(char **cmd, char **envcp, char *path, int *fd)
{
    if (execute_pipe(fd) == 1) {
        return 1;
    }
    if ((execve(path, cmd, envcp)) == -1) {
        my_putstr(cmd[0]);
        my_putstr(": Cannot run this command.\n");
        return 1;
    }
    return 0;
}

void execute_command(char **cmd, char **envcp, char *path, int *fd)
{
    int status = 0;
    pid_t pid_child = 0;

    pid_child = fork();
    if (pid_child == 0) {
        if (execute_verif(cmd, envcp, path, fd) == 1) {
            fd[5] = 1;
        }
    }
    if (pid_child > 0) {
        if (fd[2] == fd[3] - 1) {
            waitpid(pid_child, &status, 0);
            fd[5] = segfault(status);
        }
    }
}

void execute_real(char **cmd, char **config, char **envcp, int *fd)
{
    char *path = NULL;
    char **alias = NULL;

    if ((alias = alias_valid(config, cmd[0])) != NULL)
        cmd = alias;
    path = verify_paths(cmd, envcp);
    if (is_directory(cmd, cmd[0]) == true) {
        fd[5] = 1;
        return;
    }
    is_binary(cmd, fd);
    if (fd[5] == 1)
        return;
    if (fd[5] == -2) {
        is_valid_command(cmd, envcp, path, fd);
        if (alias != NULL)
            free_array(alias);
        if (fd[5] == 1)
            return;
    }
}
