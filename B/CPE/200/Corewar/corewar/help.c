/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** help.c
*/

#include "lib.h"

static void help_description(void)
{
    my_putstr("DESCRIPTION\n");
    my_putstr("    -dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_putstr("execution (if the round isn't\n");
    my_putstr("        already over) with the following format: \
32 bytes/line ");
    my_putstr("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("    -n prog_number sets the next program's \
number. By default, ");
    my_putstr("the first free number\n");
    my_putstr("        in the parameter order\n");
    my_putstr("    -a load_address sets the next program's loading \
address. ");
    my_putstr("When no address is\n");
    my_putstr("        specified, optimize the addresses so \
that the processes ");
    my_putstr("are as far\n");
    my_putstr("        away from each other as possible. The addresses are ");
    my_putstr("MEM_SIZE modulo.\n");
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./corewar [-dump nbr_cycle] ");
    my_putstr("[[-n prog_number] [-a load_address] prog_name] ...]");
    my_putstr("\n\n");
    help_description();
}
