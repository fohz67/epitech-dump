/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** construct_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "lib.h"

static bool is_valid_file(const char **av)
{
    int len = 0;

    len = my_strlen(av[1]) - 1;
    if (av[1][len] == 's' && av[1][len - 1] == '.') {
        return true;
    }
    return false;
}

static void clean_array(char **array)
{
    int i = 0;
    int j = 0;
    char *temp = NULL;

    for (; array[i] != NULL; i++) {
        j = 0;
        temp = NULL;
        for (; array[i][j] != '\0' &&
        (array[i][j] == ' ' || array[i][j] == '\t'); j++);
        if (array[i][j] != '\0') {
            temp = my_stridup(array[i], j);
            free(array[i]);
            array[i] = temp;
        }
    }
}

char **get_array(const char *av[])
{
    char **array = NULL;
    char *buffer = NULL;

    if (is_valid_file(av) == false) {
        return NULL;
    }
    if ((buffer = file_content(av[1])) == NULL) {
        return NULL;
    }
    if ((array = my_tokarray(buffer, "\n")) == NULL) {
        return NULL;
    }
    clean_array(array);
    free(buffer);
    return array;
}
