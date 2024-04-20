/*
** EPITECH PROJECT, 2022
** buffer.c
** File description:
** buffer.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "solver.h"

char *free_buf(char *buffer)
{
    if (buffer != NULL) {
        free(buffer);
    }
    return NULL;
}

int file_size(const char *path)
{
    struct stat sb;
    int size = 0;

    if (stat(path, &sb) == -1) {
        return 84;
    }
    size = sb.st_size;
    return size;
}

int file_check(const char *path, char *buffer, int size)
{
    int fd = 0;

    if ((fd = open(path, O_RDONLY)) == -1) {
        return 84;
    }
    if (read(fd, buffer, size) == -1) {
        return 84;
    }
    if (close(fd) == -1) {
        return 84;
    }
    return 0;
}

char *file_content(const char *path)
{
    int size = 0;
    char *buffer;

    if ((size = file_size(path)) == 84) {
        return NULL;
    }
    if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL) {
        return NULL;
    }
    if (file_check(path, buffer, size) == 84) {
        return free_buf(buffer);
    }
    buffer[size] = '\0';
    return buffer;
}
