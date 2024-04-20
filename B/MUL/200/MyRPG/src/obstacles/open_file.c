/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** open_file.c
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

char* open_file(const char *file)
{
    int fd = 0;
    char* buffer = NULL;
    struct stat my_stat;

    if ((fd = open(file, O_RDONLY)) == -1)
        return NULL;
    if (stat(file, &my_stat) == -1)
        return NULL;
    if ((buffer = malloc(sizeof(char) * (my_stat.st_size + 1))) == NULL)
        return NULL;
    if (read(fd, buffer, my_stat.st_size) == -1)
        return NULL;
    if (close(fd) == -1)
        return NULL;
    buffer[my_stat.st_size] = '\0';
    return buffer;
}
