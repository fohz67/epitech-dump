/*
** EPITECH PROJECT, 2022
** manage_file.c
** File description:
** manage_file.c
*/

#include "./include/my.h"

int free_buf(char *buffer)
{
    free(buffer);
    return 84;
}

int file_size(char *path)
{
    struct stat sb;
    int size = 0;

    if (stat(path, &sb) == -1) {
        return 84;
    }
    size = sb.st_size;
    return size;
}

int file_handling(char *buffer, int size)
{
    int row = 0;
    int index = 0;
    int check = 0;
    char *buffer2 = NULL;
    int result = 0;
    while (index < size) {
        if (char_checker(buffer[index]) == 1) {
            return 84;
        }
        if (buffer[index] != ENDLINE && check == 0) {
            row = row + 1;
        } else {
            check = 1;
        }
        index = index + 1;
    }
    buffer2 = my_strdup(buffer);
    result = map(buffer, buffer2, size, row + 1);
    free(buffer2);
    return result;
}

int file_content(char *path)
{
    int fd = 0;
    int size = 0;
    int result = 0;
    if ((size = file_size(path)) == 84)
        return 84;
    char *buffer = malloc(sizeof(char) * (size + 1));
    if ((fd = open(path, O_RDONLY)) == -1)
        return free_buf(buffer);
    if (read(fd, buffer, size) == -1)
        return free_buf(buffer);
    buffer[size] = '\0';
    if (close(fd) == -1)
        return free_buf(buffer);
    if (buffer == NULL || buffer[0] == '\0')
        return free_buf(buffer);
    if (occu_checker(buffer) == 1)
        return free_buf(buffer);
    result = file_handling(buffer, size);
    free(buffer);
    return result;
}
