/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** setenv.c
*/

#include <stdbool.h>
#include <stddef.h>
#include "my.h"

static void my_setenv_commit(char **envcp, char *final_name, char *final_line)
{
    int i = 0;

    for (i = 0; envcp[i] != NULL; i++) {
        if (my_strncmp(final_name, envcp[i], my_strlen(final_name)) == 0) {
            free(envcp[i]);
            break;
        }
    }
    if (envcp[i] == NULL) {
        envcp[i + 1] = NULL;
    }
    envcp[i] = my_strdup(final_line);
}

static void my_setenv_edit(char **envcp, char *final_name, char *final_value)
{
    char *final_line = NULL;

    final_line = malloc(sizeof(char) * (my_strlen(final_name) +
    my_strlen(final_value) + 2));
    if (final_line != NULL) {
        my_strcpy(final_line, final_name);
        my_strcat(final_line, "=");
        my_strcat(final_line, final_value);
        my_setenv_commit(envcp, final_name, final_line);
        free(final_line);
    }
}

static void my_setenv_data(char **cmd, char **envcp, char *name, char *value)
{
    char *final_name = NULL;
    char *final_value = NULL;

    if (name != NULL && value != NULL) {
        final_name = my_strdup(name);
        final_value = my_strdup(value);
    } else {
        final_name = my_strdup(cmd[1]);
        if (cmd[2] == NULL) {
            final_value = my_strdup("");
        } else {
            final_value = my_strdup(cmd[2]);
        }
    }
    if (final_name != NULL && final_value != NULL) {
        my_setenv_edit(envcp, final_name, final_value);
        free(final_name);
        free(final_value);
    }
}

static bool my_setenv_error(char **cmd)
{
    if (is_alpha(cmd[1][0]) == false) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return true;
    }
    for (int i = 0; cmd[i] != NULL; i++) {
        if (i > 2) {
            my_puterror("setenv: Too many arguments.\n");
            return true;
        }
    }
    for (int i = 0; cmd[1][i] != '\0'; i++) {
        if (is_alphanumeric(cmd[1][i]) == false) {
            my_puterror("setenv: Variable name must \
contain alphanumeric characters.\n");
            return true;
        }
    }
    return false;
}

int my_setenv(char **cmd, char **envcp, char *name, char *value)
{
    int result = 0;

    if (name == NULL && value == NULL) {
        if (cmd[1] == NULL) {
            result = my_env(envcp);
            return result;
        }
        if (my_setenv_error(cmd) == false) {
            my_setenv_data(cmd, envcp, name, value);
        } else {
            result = 1;
        }
    } else {
        my_setenv_data(cmd, envcp, name, value);
    }
    return result;
}
