/*
** EPITECH PROJECT, 2023
** my_tokarray.c
** File description:
** my_tokarray.c
*/

#include <string.h>
#include <stdlib.h>
#include "hangman.h"

static int size_token(const char *buffer, const char *separators)
{
    char *buffercp = NULL;
    char *token = NULL;
    int size = 0;

    buffercp = strdup(buffer);
    if (buffercp == NULL) {
        return -1;
    }
    token = strtok(buffercp, separators);
    if (token == NULL) {
        return -1;
    }
    while (token != NULL) {
        size++;
        token = strtok(NULL, separators);
    }
    free(buffercp);
    free(token);
    return size;
}

static char **construct_tokarray(char *buffer, char **array, char *separators)
{
    int i = 0;
    char *token = NULL;

    token = strtok(buffer, separators);
    if (token == NULL) {
        return NULL;
    }
    while (token != NULL) {
        array[i] = strdup(token);
        if (array[i] == NULL) {
            return NULL;
        }
        token = strtok(NULL, separators);
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
    if (size == -1) {
        return NULL;
    }
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL) {
        return NULL;
    }
    array = construct_tokarray(buffer, array, separators);
    return array;
}
