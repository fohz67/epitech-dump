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

static int execute_command(char **cmd, char **envcp, char *path)
{
    int result = 0;
    int status = 0;
    pid_t pid_child = 0;

    if (is_file(cmd, path) == true) {
        return 1;
    }
    pid_child = fork();
    if (pid_child == 0) {
        if ((execve(path, cmd, envcp)) == -1) {
            my_putstr(cmd[0]);
            my_putstr(": Cannot run this command.\n");
            result = 1;
        }
    } else if (pid_child > 0) {
        waitpid(pid_child, &status, 0);
        result = segfault(status);
    }
    return result;
}

int execute_real(char **cmd, char **envcp)
{
    int result = 0;
    char *path = NULL;

    path = verify_paths(cmd, envcp);
    if (access(cmd[0], F_OK) == 0) {
        result = execute_command(cmd, NULL, cmd[0]);
    } else if (path != NULL) {
        result = execute_command(cmd, envcp, path);
        free(path);
    } else {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
        result = 1;
    }
    return result;
}
