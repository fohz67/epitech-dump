/*
** EPITECH PROJECT, 2023
** create_content.c
** File description:
** create_content.c
*/

#include <stdlib.h>
#include "lingo.h"

int create_content(const char *path)
{
    char *buffer = NULL;
    char *word = NULL;
    char **array = NULL;
    int result = 0;

    buffer = file_content(path);
    if (buffer == NULL)
        return 84;
    array = my_tokarray(buffer, "\n");
    free(buffer);
    if (array == NULL)
        return 84;
    if (error(array) == 84) {
        free_array(array);
        return 84;
    }
    word = choose_word(array);
    result = lingo(word, my_strlen(word));
    free_array(array);
    return result;
}
