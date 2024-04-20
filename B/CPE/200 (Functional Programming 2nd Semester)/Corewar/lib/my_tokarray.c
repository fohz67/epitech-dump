/*
** EPITECH PROJECT, 2023
** my_tokarray.c
** File description:
** my_tokarray.c
*/

#include <stdlib.h>
#include "lib.h"

static int size_token(const char *buffer, const char *separators)
{
    char *buffercp = NULL;
    char *token = NULL;
    int size = 0;

    buffercp = my_strdup(buffer);
    token = my_strtok(buffercp, separators);
    while (token != NULL) {
        size++;
        token = my_strtok(NULL, separators);
    }
    free(buffercp);
    free(token);
    return size;
}

static char **construct_tokarray(char *buffer, char **array, char *separators)
{
    int i = 0;
    char *token = NULL;

    token = my_strtok(buffer, separators);
    while (token != NULL) {
        array[i] = my_strdup(token);
        if (array[i] == NULL) {
            return NULL;
        }
        token = my_strtok(NULL, separators);
        i++;
    }
    array[i] = NULL;
    free(token);
    return array;
}

char **my_tokarray(char *buffer, char *separators)
{
    char **array = NULL;
    char *tmp_buffer = NULL;
    int size = 0;

    if (buffer == NULL)
        return NULL;
    if ((tmp_buffer = my_strdup(buffer)) == NULL)
        return NULL;
    size = size_token(tmp_buffer, separators);
    if ((array = malloc(sizeof(char *) * (size + 1))) == NULL) {
        free(tmp_buffer);
        return NULL;
    }
    array = construct_tokarray(tmp_buffer, array, separators);
    free(tmp_buffer);
    return array;
}
