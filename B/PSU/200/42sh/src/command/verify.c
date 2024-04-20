/*
** EPITECH PROJECT, 2023
** verify.c
** File description:
** verify.c
*/

#include <unistd.h>
#include "my.h"

void is_binary(char **cmd, int *fd)
{
    if (access(cmd[0], F_OK) == 0) {
        if (access(cmd[0], X_OK) == -1) {
            my_puterror(cmd[0]);
            my_puterror(": Exec format error. Wrong Architecture.\n");
            fd[5] = 1;
        } else {
            execute_command(cmd, NULL, cmd[0], fd);
        }
        return;
    }
    fd[5] = -2;
}

void is_valid_command(char **cmd, char **envcp, char *path, int *fd)
{
    if (path != NULL) {
        execute_command(cmd, envcp, path, fd);
        free(path);
    } else {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
        fd[5] = 1;
    }
}
