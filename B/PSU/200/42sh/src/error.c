/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error.c
*/

#include <stddef.h>

int error(char *buffer, size_t size)
{
    if (size == 0) {
        return 84;
    }
    if (buffer[0] == '\n') {
        return 84;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != '\n' && buffer[i] != 32 && buffer[i] != '\t') {
            return 0;
        }
    }
    return 84;
}
