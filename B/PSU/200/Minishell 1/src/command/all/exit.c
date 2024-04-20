/*
** EPITECH PROJECT, 2022
** exit.c
** File description:
** exit.c
*/

#include <stdbool.h>
#include <stddef.h>
#include "my.h"

static void my_exit_free(char **cmd, char **envcp, char *buffer)
{
    free_array(cmd);
    free_array(envcp);
    free(buffer);
}

int my_exit(char **cmd, char **envcp, char *buffer, int result)
{
    if (cmd[1] != NULL && is_only_digit(cmd[1]) == false) {
        my_puterror("exit: Expression Syntax.\n");
    } else if (cmd[1] != NULL && is_only_digit(cmd[1]) == true) {
        my_putstr("exit\n");
        my_exit_free(cmd, envcp, buffer);
        exit(my_getnbr(cmd[1]));
    } else {
        my_putstr("exit\n");
        my_exit_free(cmd, envcp, buffer);
        exit(result);
    }
    return result;
}
