/*
** EPITECH PROJECT, 2023
** controllers2.c
** File description:
** controllers2.c
*/

#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include "my.h"

static int init_fd(char *filename, int *fd, int st_redirection)
{
    int result = 0;
    int fd_out = 0;

    if (filename != NULL) {
        if (st_redirection == 1) {
            fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
        if (st_redirection == 2) {
            fd_out = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
        }
        if (fd_out == -1) {
            result = 1;
        }
        fd[1] = fd_out;
        fd[4] = 1;
        free(filename);
    }
    return result;
}

static int get_name_file(char **cmd_redirection, int *fd,
int st_redirection)
{
    char **name_array = NULL;
    char *name_buffer = NULL;
    char *filename = NULL;
    int result = 0;

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

static int get_info_redirection(char **cmd_redirection, int *fd,
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
        if (get_name_file(cmd_redirection, fd, st_redirection) == 1) {
            return 1;
        }
    }
    return 0;
}

static int check_redirection_type(char *buffer, char **cmd_redirection, int *fd)
{
    int nb_redirection = 0;
    int st_redirection = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '>' && buffer[i + 1] != '>') {
            nb_redirection++;
            st_redirection = 1;
        }
        if (buffer[i] == '>' && buffer[i + 1] == '>') {
            nb_redirection++;
            st_redirection = 2;
            i++;
        }
    }
    if (get_info_redirection(cmd_redirection, fd, nb_redirection,
    st_redirection) == 1)
        return 1;
    return 0;
}

int controller_redirection(char **envcp, char **config, char *buffer, int *fd)
{
    char *buffer_cpy = NULL;
    char **cmd_redirection = NULL;

    if ((buffer_cpy = my_strdup(buffer)) == NULL)
        return 1;
    if ((cmd_redirection = my_tokarray(buffer_cpy, ">\n")) == NULL)
        return 1;
    if (check_redirection_type(buffer, cmd_redirection, fd) == 1)
        return 1;
    fd[5] = controller_input_redirect(envcp, config, buffer, fd);
    if (fd[5] == 1)
        return 1;
    if (fd[4] == 1)
        if (close(fd[1]) == -1)
            return 1;
    free(buffer_cpy);
    free_array(cmd_redirection);
    return fd[5];
}
