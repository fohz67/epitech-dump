/*
** EPITECH PROJECT, 2023
** read_user.c
** File description:
** read_user.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

char read_user(void)
{
    char *buffer = NULL;
    int status = 0;
    size_t size = 0;
    int len_input = 0;
    char letter = 'a';

    printf("Your letter: ");
    status = getline(&buffer, &size, stdin);
    if (status < 0 || status == EOF) {
        return -1;
    }
    if (buffer == NULL || my_strlen(buffer) > 2) {
        return -1;
    }
    len_input = my_strlen(buffer);
    buffer[len_input - 1] = '\0';
    letter = buffer[0];
    free(buffer);
    return letter;
}
