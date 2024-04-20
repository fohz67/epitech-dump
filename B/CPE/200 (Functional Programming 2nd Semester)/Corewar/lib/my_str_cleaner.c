/*
** EPITECH PROJECT, 2023
** my_str_cleaner.c
** File description:
** my_str_cleaner.c
*/

#include <stdlib.h>
#include "lib.h"
#include "asm.h"

static void remove_separator(char *buffer, int index, int *len_buffer)
{
    int i;
    int length = *len_buffer;

    for (i = index; i < length; i++) {
        buffer[i] = buffer[i + 1];
    }
    *len_buffer = length - 1;
}

static int is_separator(char c, const char *separators)
{
    int len_separators = 0;

    len_separators = my_strlen(separators);
    for (int i = 0; i < len_separators; i++) {
        if (c == separators[i]) {
            return 1;
        }
    }
    return 0;
}

char *my_str_begin_cleaner(char *buffer, const char *separators)
{
    char *str = NULL;
    int i = 0;
    int j = 0;

    if (buffer == NULL || separators == NULL) {
        return NULL;
    }
    if ((str = malloc(sizeof(char) * (my_strlen(buffer) + 1))) == NULL) {
        return NULL;
    }
    for (; buffer[i] == ' '; i++);
    for (; buffer[i] != '\0'; i++) {
        str[j] = buffer[i];
        j++;
    }
    str[j] = '\0';
    free(buffer);
    return str;
}

char *my_str_cleaner(char *buffer, const char *separators)
{
    int len_buffer = 0;
    int i = 0;

    if (buffer == NULL || separators == NULL) {
        return NULL;
    }
    len_buffer = my_strlen(buffer);
    while (i < len_buffer) {
        if (is_separator(buffer[i], separators)) {
            remove_separator(buffer, i, &len_buffer);
        } else {
            i++;
        }
    }
    return buffer;
}
