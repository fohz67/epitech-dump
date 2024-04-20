/*
** EPITECH PROJECT, 2023
** config.c
** File description:
** config.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "scripting.h"
#include "prompt.h"

char *read_script(char *path)
{
    int fd = 0;
    int size = 0;
    char *file = NULL;
    struct stat stb;

    if (stat(path, &stb) == -1)
        return NULL;
    file = malloc(sizeof(char) * stb.st_size + 1);
    if (file == NULL)
        return NULL;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return NULL;
    size = read(fd, file, stb.st_size);
    if (size == 0)
        return NULL;
    file[size] = '\0';
    return file;
}
