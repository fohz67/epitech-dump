/*
** EPITECH PROJECT, 2023
** read_user.c
** File description:
** read_user
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lingo.h"

char *read_user(void)
{
    char *buffer = NULL;
    int status = 0;
    size_t size = 0;
    int len_input = 0;

    printf(">");
    status = getline(&buffer, &size, stdin);
    if (status < 0) {
        return NULL;
    }
    if (buffer == NULL) {
        return NULL;
    }
    len_input = my_strlen(buffer);
    buffer[len_input - 1] = '\0';
    return buffer;
}
