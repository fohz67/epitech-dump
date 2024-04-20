/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-eddy.gardes
** File description:
** write_args
*/

#include <unistd.h>
#include <stdint.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void write_args(body_args *body, int fd)
{
    char c_arg = 0;
    short s_arg = 0;

    if (body->coding_byte[body->index_cb] == 1) {
        c_arg = body->i_arg;
        write(fd, &c_arg, sizeof(char));
    }
    if (body->coding_byte[body->index_cb] == 2) {
        body->i_arg = convert_big_endian_int(body->i_arg);
        write(fd, &body->i_arg, sizeof(int));
    }
    if (body->coding_byte[body->index_cb] == 3) {
        s_arg = int_to_short(body->i_arg);
        s_arg = convert_big_endian_short(s_arg);
        write(fd, &s_arg, sizeof(short));
    }
}

void write_index(body_args *body, int fd)
{
    short s_arg = 0;

    s_arg = int_to_short(body->i_arg);
    s_arg = convert_big_endian_short(s_arg);
    write(fd, &s_arg, sizeof(short));
}
