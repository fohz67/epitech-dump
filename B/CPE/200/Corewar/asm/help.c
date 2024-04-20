/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** help.c
*/

#include "asm.h"
#include "lib.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./asm file_name[.s]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    file_name file in assembly language to be converted ");
    my_putstr("into file_name.cor, an\n");
    my_putstr("    executable in the Virtual Machine.\n");
    return 0;
}
