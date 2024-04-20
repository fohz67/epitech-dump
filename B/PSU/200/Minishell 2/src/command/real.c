/*
** EPITECH PROJECT, 2022
** real.c
** File description:
** real.c
*/

#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include "my.h"

int execute_pipe(int *fd)
{
    int result = 0;

    if (fd[0] != STDIN_FILENO) {
        if (dup2(fd[0], STDIN_FILENO) == -1) {
            return 1;
        }
        if (close(fd[0]) == -1) {
            return 1;
        }
    }
    if (fd[1] != STDOUT_FILENO) {
        if (dup2(fd[1], STDOUT_FILENO) == -1) {
            return 1;
        }
        if (close(fd[1]) == -1) {
            return 1;
        }
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

int execute_command(char **cmd, char **envcp, char *path, int *fd)
{
    int result = 0;
    int status = 0;
    pid_t pid_child = 0;

    pid_child = fork();
    if (pid_child == 0) {
        if (execute_verif(cmd, envcp, path, fd) == 1) {
            return 1;
        }
    }
    if (pid_child > 0) {
        if (fd[2] == fd[3] - 1) {
            waitpid(pid_child, &status, 0);
            result = segfault(status);
        }
    }
    return result;
}

int execute_real(char **cmd, char **envcp, int *fd)
{
    int result = 0;
    char *path = NULL;

    path = verify_paths(cmd, envcp);
    if (is_directory(cmd, cmd[0]) == true) {
        return 1;
    }
    if (is_binary(cmd, fd) == 1) {
        return 1;
    }
    if (is_valid_command(cmd, envcp, path, fd) == 1) {
        return 1;
    }
    return result;
}
