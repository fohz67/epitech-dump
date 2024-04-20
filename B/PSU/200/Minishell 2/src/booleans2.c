/*
** EPITECH PROJECT, 2022
** booleans2.c
** File description:
** booleans2.c
*/

#include <sys/stat.h>
#include "my.h"

bool is_last_command(char **cmd, char *path)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], path) != 0) {
            continue;
        }
        if (cmd[i + 1] == NULL) {
            return true;
        }
    }
    return false;
}

bool is_bin(char *filename)
{
    struct stat st;

    if (lstat(filename, &st) != 0) {
        my_puterror(filename);
        my_puterror(": Exec format error. Wrong Architecture.\n");
        return false;
    }
    if (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR) && !S_ISDIR(st.st_mode)) {
        return true;
    }
    my_puterror(filename);
    my_puterror(": Exec format error. Wrong Architecture.\n");
    return false;
}
