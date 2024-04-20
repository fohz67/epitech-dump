/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <signal.h>
#include "my.h"

static int loop_main(char **envcp)
{
    int result = 0;
    size_t size = 0;
    char *buffer = NULL;

    my_putstr("> ");
    while (getline(&buffer, &size, stdin) != EOF) {
        if (error(buffer, size) != 84) {
            result = controller_separators(envcp, buffer, result);
        }
        buffer[0] = '\0';
        my_putstr("> ");
    }
    free(buffer);
    return result;
}

int main(int ac, const char **, const char **env)
{
    int result = 0;
    char **envcp = NULL;

    envcp = copy_env(env);
    if (ac != 1) {
        return 84;
    }
    if (envcp == NULL) {
        return 84;
    }
    result = loop_main(envcp);
    free_array(envcp);
    return result;
}
