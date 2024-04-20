/*
** EPITECH PROJECT, 2023
** booleans.c
** File description:
** booleans.c
*/

#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

bool is_directory(char **cmd, char *path)
{
    struct stat sb;

    if (path == NULL) {
        return true;
    }
    if (stat(path, &sb) == 0) {
        if (S_ISDIR(sb.st_mode)) {
            my_puterror(cmd[0]);
            my_puterror(": Permission denied.\n");
            return true;
        }
    }
    return false;
}

bool is_only_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

bool is_alpha(const char c)
{
    if ((c < 'A' || c > 'Z') &&
        (c < 'a' || c > 'z')) {
        return false;
    }
    return true;
}

bool is_alphanumeric(const char c)
{
    if ((c < 'A' || c > 'Z') &&
        (c < 'a' || c > 'z') &&
        (c < '0' || c > '9')) {
        return false;
    }
    return true;
}

bool is_artificial_cmd(char *cmd)
{
    static const char *all_cmds[] = {"cd", "env", "exit", "setenv",
    "unsetenv", "echo", NULL};

    if (my_strncmp("\\", cmd, 1) == 0) {
        return true;
    }
    for (int i = 0; all_cmds[i] != NULL; i++) {
        if (my_strcmp(all_cmds[i], cmd) == 0) {
            return true;
        }
    }
    return false;
}
