/*
** EPITECH PROJECT, 2022
** manage_file.c
** File description:
** manage_file.c
*/

#include "../include/my.h"

int free_buf(char *buffer)
{
    free(buffer);
    return ERROR;
}

int file_size(char *path)
{
    struct stat sb;
    int size = 0;

    if (stat(path, &sb) == ERROR_FILE) {
        return ERROR;
    }
    size = sb.st_size;
    return size;
}

int file_content(char *path)
{
    int fd = 0;
    int size = 0;
    struct square b = {0, 0, 0, 0, 0, 0};

    if ((size = file_size(path)) == ERROR)
        return ERROR;
    char *buffer = malloc(sizeof(char) * (size + 1));
    if ((fd = open(path, O_RDONLY)) == ERROR_FILE)
        return free_buf(buffer);
    if (read(fd, buffer, size) == ERROR_FILE)
        return free_buf(buffer);
    if (close(fd) == ERROR_FILE)
        return free_buf(buffer);
    buffer[size] = '\0';
    if (buffer[0] == '\0')
        return free_buf(buffer);
    if (buffer[0] < '0' && buffer[0] > '9')
        return free_buf(buffer);
    return handling(buffer, size, b);
}
