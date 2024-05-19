/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** error.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include "my.h"

static bool is_isolated_semicolon(char *str, int index)
{
    if (str[index] == ';' && (index == 0 || str[index - 1] == '\n')
        && (str[index + 1] == '\0' || str[index + 1] == '\n')) {
        return true;
    } else {
        return false;
    }
}

static bool is_digit(char c)
{
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

static bool is_valid_string(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == ';' || str[i] == '.') {
            continue;
        }
        if (!is_digit(str[i])) {
            return false;
        }
        if (is_isolated_semicolon(str, i)) {
            return false;
        }
    }
    return true;
}

static char *read_file_contents(int fd)
{
    struct stat file_stat;
    char *buffer = NULL;
    int bytes_read = 0;

    if (fstat(fd, &file_stat) == -1) {
        return NULL;
    }
    buffer = malloc(file_stat.st_size + 1);
    bytes_read = read(fd, buffer, file_stat.st_size);
    buffer[file_stat.st_size] = '\0';
    if (bytes_read == -1 || bytes_read == 0) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

int error(const char *filename)
{
    int fd = 0;
    char *file_contents = NULL;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 84;
    }
    file_contents = read_file_contents(fd);
    close(fd);
    if (file_contents == NULL) {
        return 84;
    }
    if (!is_valid_string(file_contents)) {
        free(file_contents);
        return 84;
    }
    free(file_contents);
    return 0;
}
