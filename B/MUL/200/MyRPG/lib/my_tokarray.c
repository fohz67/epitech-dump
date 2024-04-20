/*
** EPITECH PROJECT, 2022
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
    int size = 0;

    size = size_token(buffer, separators);
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL) {
        return NULL;
    }
    array = construct_tokarray(buffer, array, separators);
    return array;
}
