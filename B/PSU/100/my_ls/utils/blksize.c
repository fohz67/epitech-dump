/*
** EPITECH PROJECT, 2022
** blksize.c
** File description:
** blksize.c
*/

#include <sys/stat.h>
#include "../include/my.h"

long int blksize(char **tab, const char *path, int size)
{
    char final_path[1000] = {0};
    int final_length = 0;
    long int blk = 0;
    struct stat sb;

    my_strcpy(final_path, path);
    final_length = my_strlen(final_path);

    if (final_path[final_length] != '/') {
        my_strcat(final_path, "/");
        final_length = final_length + 1;
    }

    my_strcat(final_path, tab[size]);
    stat(final_path, &sb);

    blk = sb.st_blksize / 1000;
    final_path[0] = '\0';
    return blk;
}
