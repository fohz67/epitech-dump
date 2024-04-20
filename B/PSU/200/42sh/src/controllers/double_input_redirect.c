/*
** EPITECH PROJECT, 2022
** double_input_redirect.c
** File description:
** double_input_redirect.c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "my.h"

static void double_redirect_child(char *filename)
{
    char *buffer = NULL;
    size_t size = 0;
    int size_word = 0;

    size_word = strlen(filename);
    while (buffer == NULL || strncmp(filename, buffer, size_word) != 0) {
        write(1, "? ", 2);
        if (getline(&buffer, &size, stdin) == EOF) {
            break;
        }
    }
    free(buffer);
}

void double_redirect_par(char* filename)
{
    int pid = 0;

    pid = fork();
    if (pid == 0) {
        double_redirect_child(filename);
        exit(0);
    } else {
        waitpid(pid, NULL, 0);
    }
}
