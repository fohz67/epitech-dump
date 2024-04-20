/*
** EPITECH PROJECT, 2022
** verify.c
** File description:
** verify.c
*/

#include <unistd.h>
#include "my.h"

int is_binary(char **cmd, int *fd)
{
    int result = 0;

    if (access(cmd[0], F_OK) == 0) {
        if (access(cmd[0], X_OK) == -1) {
            my_puterror(cmd[0]);
            my_puterror(": Exec format error. Wrong Architecture.\n");
            result = 1;
        } else {
            result = execute_command(cmd, NULL, cmd[0], fd);
        }
    }
    return result;
}

int is_valid_command(char **cmd, char **envcp, char *path, int *fd)
{
    int result = 0;

    if (path != NULL) {
        result = execute_command(cmd, envcp, path, fd);
        free(path);
    } else {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
        result = 1;
    }
    return result;
}
