/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** unsetenv.c
*/

#include <stddef.h>
#include "my.h"

static void my_unsetenv_removevariable(char **envcp, int j)
{
    for (; envcp[j] != NULL; j++) {
        free(envcp[j]);
        if (envcp[j + 1] == NULL) {
            envcp[j] = NULL;
            return;
        } else {
            envcp[j] = my_strdup(envcp[j + 1]);
        }
    }
}

static int my_unsetenv_getvariable(char **cmd, char **envcp, int i)
{
    int j = 0;

    for (j = 0; envcp[j] != NULL; j++) {
        if (my_strncmp(cmd[i], envcp[j], my_strlen(cmd[i])) == 0) {
            return j;
        }
    }
    return j;
}

int my_unsetenv(char **cmd, char **envcp)
{
    int result = 0;
    int j = 0;

    for (int i = 1; cmd[i] != NULL; i++) {
        j = my_unsetenv_getvariable(cmd, envcp, i);
        if (envcp[j] != NULL) {
            my_unsetenv_removevariable(envcp, j);
        }
    }
    return result;
}
