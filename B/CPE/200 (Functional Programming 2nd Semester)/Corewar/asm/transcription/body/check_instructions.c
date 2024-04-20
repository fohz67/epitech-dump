/*
** EPITECH PROJECT, 2023
** check_instructions.c
** File description:
** check_instructions.c
*/

#include <unistd.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int check_instructions(body_args *body, int fd)
{
    int i = 0;
    int pos_struct = 0;

    for (; i != 16; i++) {
        pos_struct = condition_instructions(body, i);
        if (pos_struct != -1) {
            write(fd, &op_tab[pos_struct].code, sizeof(char));
            return pos_struct;
        }
    }
    return -1;
}
