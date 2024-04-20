/*
** EPITECH PROJECT, 2023
** my_tokarray.c
** File description:
** my_tokarray.c
*/

#include <string.h>
#include "my.h"

static int size_token(const char *buffer, const char *separators)
{
    char *buffercp = NULL;
    char *token = NULL;
    int size = 0;

    if ((buffercp = my_strdup(buffer)) == NULL) {
        return -1;
    }
    token = my_strtok(buffercp, separators);
    while (token != NULL) {
        size++;
        token = my_strtok(NULL, separators);
    }
    free(buffercp);
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
            free_array(array);
            free(token);
            return NULL;
        }
        token = my_strtok(NULL, separators);
        i++;
    }
    array[i] = NULL;
    free(token);
    return array;
}

char **my_tokarray_duo(char *buffer, char *separators)
{
    char **array = NULL;
    int size = 0;

    if (buffer == NULL) {
        return NULL;
    }
    if ((size = size_token(buffer, separators)) == -1) {
        return NULL;
    }
    if ((array = malloc(sizeof(char *) * (size + 1))) == NULL) {
        return NULL;
    }
    array = construct_tokarray(buffer, array, separators);
    return array;
}
