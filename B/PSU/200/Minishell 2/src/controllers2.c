/*
** EPITECH PROJECT, 2022
** controllers2.c
** File description:
** controllers2.c
*/

#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include "my.h"

static int controller_redirection_close(char *filename, int *fd)
{
    if (filename != NULL) {
        if (close(fd[1]) == -1) {
            return 1;
        }
        free(filename);
    }
    return 0;
}

static int controller_redirection_error(char **cmd_redirection,
int nb_redirection)
{
    if (cmd_redirection[1] == NULL) {
        my_puterror("Missing name for redirect.\n");
        return 1;
    }
    if (nb_redirection > 1) {
        my_puterror("Ambiguous output redirect.\n");
        return 1;
    }
    return 0;
}

static int controller_redirection3(char *filename, char **cmd_redirection,
int *fd)
{
    char **array = NULL;
    char *buffer_cpy = NULL;

    if ((buffer_cpy = my_strdup(cmd_redirection[1])) == NULL) {
        return 1;
    }
    if ((array = my_tokarray(buffer_cpy, " \t\n")) == NULL) {
        return 1;
    }
    filename = my_strdup(array[0]);
    free(buffer_cpy);
    free_array(array);
    if (filename != NULL) {
        int fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
        if (fd_out == -1) {
            return 1;
        }
        fd[1] = fd_out;
    }
    return 0;
}

static int controller_redirection2(char *buffer, char *filename,
char **cmd_redirection, int *fd)
{
    int nb_redirection = 0;
    int result = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '>') {
            nb_redirection++;
        }
    }
    if (nb_redirection > 0) {
        if (controller_redirection_error(cmd_redirection,
        nb_redirection) == 1) {
            return 1;
        }
        if (controller_redirection3(filename, cmd_redirection, fd) == 1) {
            return 1;
        }
    }
    return result;
}

int controller_redirection(char **envcp, char *buffer, int result, int *fd)
{
    char *filename = NULL;
    char *buffer_cpy = NULL;
    char **cmd_redirection = NULL;

    if ((buffer_cpy = my_strdup(buffer)) == NULL)
        return 1;
    if ((cmd_redirection = my_tokarray(buffer_cpy, ">\n")) == NULL)
        return 1;
    if (controller_redirection2(buffer, filename, cmd_redirection, fd) == 1) {
        result = 1;
    } else if (engine_main(envcp, buffer, result, fd) == 1) {
        result = 1;
    }
    if (controller_redirection_close(filename, fd) == 1){
        result = 1;
    }
    free(buffer_cpy);
    free_array(cmd_redirection);
    return result;
}
