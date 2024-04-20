/*
** EPITECH PROJECT, 2022
** artificial.c
** File description:
** artificial.c
*/

#include "my.h"

int execute_artificial(char **cmd, char **envcp, char *buffer, int result)
{
    static const char *all_cmds[] = {"cd", "env", "exit", "setenv",
    "unsetenv"};

    if (my_strcmp(cmd[0], all_cmds[0]) == 0) {
        result = my_cd(cmd, envcp);
    }
    if (my_strcmp(cmd[0], all_cmds[1]) == 0) {
        result = my_env(cmd, envcp);
    }
    if (my_strcmp(cmd[0], all_cmds[2]) == 0) {
        result = my_exit(cmd, envcp, buffer, result);
    }
    if (my_strcmp(cmd[0], all_cmds[3]) == 0) {
        result = my_setenv(cmd, envcp, NULL, NULL);
    }
    if (my_strcmp(cmd[0], all_cmds[4]) == 0) {
        result = my_unsetenv(cmd, envcp);
    }
    return result;
}
