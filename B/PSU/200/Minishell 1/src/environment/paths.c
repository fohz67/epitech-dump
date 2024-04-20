/*
** EPITECH PROJECT, 2022
** paths.c
** File description:
** paths.c
*/

#include <unistd.h>
#include <string.h>
#include "my.h"

static char* parse_paths(char **cmd, char **array_paths)
{
    char *path = NULL;

    for (int i = 0; array_paths[i] != NULL; i++) {
        path = malloc((sizeof(char) *
        my_strlen(cmd[0]) + my_strlen(array_paths[i]) + 2));
        my_strcpy(path, array_paths[i]);
        my_strcat(path, "/");
        my_strcat(path, cmd[0]);
        if (access(path, F_OK) == 0) {
            free_array(array_paths);
            return path;
        }
        free(path);
    }
    free_array(array_paths);
    return NULL;
}

char *verify_paths(char **cmd, char **envcp)
{
    char *buffer_paths = NULL;
    char **array_paths = NULL;

    buffer_paths = retrieve_data_env(envcp, "PATH=", 5);
    if (buffer_paths == NULL) {
        return NULL;
    }
    array_paths = my_tokarray(buffer_paths, "=:");
    free(buffer_paths);
    return parse_paths(cmd, array_paths);
}
