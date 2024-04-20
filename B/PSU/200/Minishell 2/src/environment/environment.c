/*
** EPITECH PROJECT, 2022
** environment.c
** File description:
** environment.c
*/

#include "my.h"

char *retrieve_data_env(char **envcp, char *name, int n)
{
    char *str = NULL;

    for (int i = 0; envcp[i] != NULL; i++) {
        if (my_strncmp(name, envcp[i], n) == 0) {
            str = my_stridup(envcp[i], n);
        }
    }
    return str;
}

char **copy_env(const char **env)
{
    int i = 0;
    char **envcp = NULL;

    if (env == NULL) {
        return NULL;
    }
    for (i = 0; env[i] != NULL; i++);
    envcp = malloc(sizeof(char *) * (i * 2));
    if (envcp == NULL) {
        return NULL;
    }
    for (i = 0; env[i] != NULL; i++) {
        envcp[i] = my_strdup(env[i]);
        if (envcp[i] == NULL) {
            return NULL;
        }
    }
    envcp[i] = NULL;
    return envcp;
}
