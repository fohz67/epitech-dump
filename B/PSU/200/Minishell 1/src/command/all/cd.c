/*
** EPITECH PROJECT, 2022
** cd.c
** File description:
** cd.c
*/

#include <sys/stat.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"

static int my_cd_home(char **cmd, char **envcp, char *home)
{
    int result = 0;
    char *cwd = NULL;

    cwd = getcwd(NULL, 0);
    my_setenv(cmd, envcp, "OLDPWD", cwd);
    chdir(home);
    my_setenv(cmd, envcp, "PWD", home);
    free(cwd);
    return result;
}

static int my_cd_isdir(char **cmd, char **envcp, char *path, struct stat sb)
{
    char *cwd = NULL;
    int result = 0;

    if (S_ISDIR(sb.st_mode)) {
        cwd = getcwd(NULL, 0);
        my_setenv(cmd, envcp, "OLDPWD", cwd);
        chdir(path);
        my_setenv(cmd, envcp, "PWD", cwd);
        result = 0;
        free(cwd);
    } else {
        my_puterror(path);
        my_puterror(": Not a directory.\n");
        result = 1;
    }
    return result;
}

static int my_cd_move(char **cmd, char **envcp, char *path)
{
    int result = 0;
    struct stat sb;

    if (stat(path, &sb) == 0) {
        result = my_cd_isdir(cmd, envcp, path, sb);
    } else {
        my_puterror(path);
        my_puterror(": No such file or directory.\n");
        result = 1;
    }
    return result;
}

static int my_cd_argument(char **cmd, char **envcp)
{
    int result = 0;
    char *path = NULL;

    if (my_strcmp(cmd[1], "-") == 0) {
        path = retrieve_data_env(envcp, "OLDPWD=", 7);
    } else {
        path = my_strdup(cmd[1]);
    }
    if (path != NULL) {
        result = my_cd_move(cmd, envcp, path);
        free(path);
    } else {
        my_puterror(": No such file or directory.\n");
        result = 1;
    }
    return result;
}

int my_cd(char **cmd, char **envcp)
{
    int result = 0;
    char *home = NULL;

    if (cmd[1] == NULL || (cmd[1] != NULL && my_strcmp(cmd[1], "~") == 0)) {
        home = retrieve_data_env(envcp, "HOME=", 5);
        if (home != NULL) {
            result = my_cd_home(cmd, envcp, home);
            free(home);
        } else {
            my_puterror("cd: No home directory.\n");
            result = 1;
        }
    } else if (cmd[2] == NULL) {
        result = my_cd_argument(cmd, envcp);
    } else {
        my_puterror("cd: Too many arguments.");
        result = 1;
    }
    return result;
}
