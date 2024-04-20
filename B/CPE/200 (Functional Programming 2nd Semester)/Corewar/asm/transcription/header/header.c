/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

static int create_file_cor(header_t header, data_t *data, body_args *body,
const char *av[])
{
    int fd = 0;
    char *path = NULL;

    if ((path = malloc(sizeof(char) *
    (my_strlen(av[1]) + 3))) == NULL)
        return 84;
    my_strncpy(path, av[1], my_strlen(av[1]) - 2);
    my_strcat(path, ".cor");
    path[my_strlen(av[1]) + 3] = '\0';
    path = my_str_lowercase(path);
    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd == -1) {
        free(path);
        return 84;
    }
    write(fd, &header, sizeof(header_t));
    convert_body_into_binary(data, body, fd);
    close(fd);
    free(path);
    return 0;
}

int fill_struct(data_t *data, body_args *body, const char *av[])
{
    header_t header = {0};

    data->name = my_str_begin_cleaner(data->name, " ");
    data->comment = my_str_begin_cleaner(data->comment, " ");
    header.magic = COREWAR_EXEC_MAGIC;
    header.magic = convert_big_endian_int(header.magic);
    header.prog_size = 0;
    if (data->instructions[0] != NULL) {
        header.prog_size = prog_size(data);
    }
    header.prog_size = convert_big_endian_int(header.prog_size);
    my_memset(header.prog_name, 0, PROG_NAME_LENGTH);
    if (data->comment != NULL)
        my_memset(header.comment, 0, COMMENT_LENGTH);
    my_strcpy(header.prog_name, data->name);
    if (data->comment != NULL)
        my_strcpy(header.comment, data->comment);
    if (create_file_cor(header, data, body, av) == 84)
        return 84;
    return 0;
}
