/*
** EPITECH PROJECT, 2022
** buffer.c
** File description:
** buffer.c
*/

#include "./include/my.h"

int free_buf(char *buffer)
{
    free(buffer);
    return ERROR;
}

int file_size(const char *path)
{
    struct stat sb;
    int size = 0;

    if (stat(path, &sb) == ERROR_FILE) {
        return ERROR;
    }
    size = sb.st_size;
    return size;
}

int file_check(const char *path, char *buffer, int size)
{
    int fd = 0;
    int read_nb = 0;
    int close_nb = 0;

    fd = open(path, O_RDONLY);
    read_nb = read(fd, buffer, size);
    close_nb = close(fd);

    if (fd == ERROR_FILE || read_nb == ERROR_FILE || close_nb == ERROR_FILE) {
        return ERROR;
    }
    return 0;
}

int file_content(const char *path, struct utils *utils)
{
    int size = 0;
    char *buffer = {0};

    if ((size = file_size(path)) == ERROR) {
        write(1, BAD_USAGE, my_strlen(BAD_USAGE));
        return ERROR;
    }
    buffer = malloc(sizeof(char) * (size + 1));
    if (file_check(path, buffer, size) == ERROR) {
        write(1, BAD_USAGE, my_strlen(BAD_USAGE));
        return free_buf(buffer);
    }
    buffer[size] = ENDSTR;
    if (file_errors(buffer) == ERROR) {
        write(1, INVALID, my_strlen(INVALID));
        return free_buf(buffer);
    }
    matrix_content(buffer, utils);
    return SUCCESS;
}
