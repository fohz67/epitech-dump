/*
** EPITECH PROJECT, 2023
** get_alias.c
** File description:
** get_alias.c
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "scripting.h"

char **return_alias(char **file, char *cmd, int i)
{
    char **command = NULL;
    char **alias = NULL;

    if (my_strncmp(file[i], "alias", 5) == 0 && file[i][0] != '#'
    && check_alias(file[i]) == 2)
        command = my_tokarray(file[i], ":\n");
    if (command == NULL)
        return NULL;
    if (my_strcmp(command[1], cmd) == 0) {
        alias = my_tokarray(command[2], " ");
        if (alias == NULL) {
            free_array(command);
            return NULL;
        }
        free_array(command);
    }
    return alias;
}

char **get_alias(char **file, char *cmd)
{
    char **alias = NULL;

    if (file[0] == NULL)
        return NULL;
    for (int i = 0; file[i] != NULL; i++) {
        if (alias == NULL)
            alias = return_alias(file, cmd, i);
    }
    return alias;
}
