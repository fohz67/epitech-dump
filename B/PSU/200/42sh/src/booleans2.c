/*
** EPITECH PROJECT, 2023
** booleans2.c
** File description:
** booleans2.c
*/

#include <dirent.h>
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

int get_if_repo(void)
{
    DIR *dir = NULL;

    dir = opendir(".git");
    if (dir == NULL)
        return 0;
    if (closedir(dir) == -1)
        return 0;
    return 1;
}
