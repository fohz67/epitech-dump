/*
** EPITECH PROJECT, 2023
** get_object.c
** File description:
** get_object.c
*/

#include <unistd.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int get_coding_byte(body_args *body, int fd)
{
    char byte = 0b00000000;

    for (int i = 0; i != 4; i++) {
        if (body->coding_byte[i] == 1) {
            byte |= (REG_V << 2 * (3 - i));
        }
        if (body->coding_byte[i] == 2) {
            byte |= (DIR_V << 2 * (3 - i));
        }
        if (body->coding_byte[i] == 3) {
            byte |= (IND_V << 2 * (3 - i));
        }
    }
    write(fd, &byte, sizeof(char));
    return 0;
}
