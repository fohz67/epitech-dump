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

static int my_exit_result(int result)
{
    int nb = 0;

    for (; result > 255; result --) {
        if (nb == 255) {
            nb = 0;
        } else {
            nb++;
        }
    }
    return nb - 1;
}

int my_exit(char **cmd, char **envcp, char *buffer, int result)
{
    if (cmd[1] != NULL && is_only_digit(cmd[1]) == false) {
        my_puterror("exit: Expression Syntax.\n");
        return 1;
    }
    if (cmd[1] != NULL && is_only_digit(cmd[1]) == true) {
        my_putstr("exit\n");
        if (my_getnbr(cmd[1]) > 255) {
            result = my_exit_result(my_getnbr(cmd[1]));
        }
        my_exit_free(cmd, envcp, buffer);
        exit(result);
    } else {
        my_putstr("exit\n");
        my_exit_free(cmd, envcp, buffer);
        exit(result);
    }
    return result;
}
