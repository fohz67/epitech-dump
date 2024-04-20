/*
** EPITECH PROJECT, 2022
** input_redirect.c
** File description:
** input_redirect.c
*/

#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include "my.h"

static int init_fd(char *filename, int *fd, int st_redirection)
{
    int result = 0;
    int fd_in = 0;

    if (filename != NULL) {
        if (st_redirection == 1) {
            fd_in = open(filename, O_RDONLY, 0644);
            fd[0] = fd_in;
            fd[6] = 1;
        }
        if (fd_in == -1) {
            my_puterror(filename);
            my_puterror(": No such file or directory.\n");
            result = 1;
        }
        if (st_redirection == 2) {
            double_redirect_par(filename);
        }
        free(filename);
    }
    return result;
}

static int input_redirect(char **cmd_redirection, int *fd,
int st_redirection)
{
    int result = 0;
    char **name_array = NULL;
    char *name_buffer = NULL;
    char *filename = NULL;

    if ((name_buffer = my_strdup(cmd_redirection[1])) == NULL) {
        return 1;
    }
    if ((name_array = my_tokarray(name_buffer, " \t\n")) == NULL) {
        return 1;
    }
    if (name_array[0] == NULL) {
        my_puterror("Missing name for redirect.\n");
        return 1;
    }
    filename = my_strdup(name_array[0]);
    result = init_fd(filename, fd, st_redirection);
    free(name_buffer);
    free_array(name_array);
    return result;
}

static int get_errors(char **cmd_redirection, int *fd,
int nb_redirection, int st_redirection)
{
    if (nb_redirection > 0) {
        if (cmd_redirection[1] == NULL) {
            my_puterror("Missing name for redirect.\n");
            return 1;
        }
        if (nb_redirection > 1) {
            my_puterror("Ambiguous output redirect.\n");
            return 1;
        }
        if (st_redirection == 0) {
            return 1;
        }
        if (input_redirect(cmd_redirection, fd, st_redirection) == 1) {
            return 1;
        }
    }
    return 0;
}

static int check_redirect(char *buffer, char **cmd_redirection, int *fd)
{
    int nb_redirection = 0;
    int st_redirection = 0;
    int result = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '<' && buffer[i + 1] != '<') {
            nb_redirection++;
            st_redirection = 1;
        }
        if (buffer[i] == '<' && buffer[i + 1] == '<') {
            nb_redirection++;
            st_redirection = 2;
            i++;
        }
    }
    if (get_errors(cmd_redirection, fd, nb_redirection, st_redirection) == 1)
        return 1;
    return result;
}

int controller_input_redirect(char **envcp, char **config,
char *buffer, int *fd)
{
    char *buffer_cpy = NULL;
    char **cmd_redirection = NULL;

    if ((buffer_cpy = my_strdup(buffer)) == NULL) {
        return 1;
    }
    if ((cmd_redirection = my_tokarray(buffer_cpy, "<\n")) == NULL) {
        return 1;
    }
    if (check_redirect(buffer, cmd_redirection, fd) == 1) {
        return 1;
    }
    engine_main(envcp, config, buffer, fd);
    if (fd[6] == 1) {
        close(fd[0]);
    }
    free(buffer_cpy);
    free_array(cmd_redirection);
    return fd[5];
}
