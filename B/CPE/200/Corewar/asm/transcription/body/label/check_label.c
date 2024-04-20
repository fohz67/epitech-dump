/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-eddy.gardes
** File description:
** check_label
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "asm.h"

int is_index(char *instruction)
{
    const char *exceptions[] = {"ldi", "zjmp", "fork", "sti", NULL};

    for (int i = 0; exceptions[i] != NULL; i++) {
        if (my_strcmp(instruction, exceptions[i]) == 0)
            return 1;
    }
    return 0;
}

char* is_label(char* line, int j)
{
    char* name_label = NULL;

    if ((line[j] < '0' || line[j] > '9') && line[j] == ':') {
        if ((name_label = get_name_label(line, j)) == NULL)
            return NULL;
    }
    return name_label;
}

int verif_conding_byte(char *instruction)
{
    const char* exceptions[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; exceptions[i] != NULL; i++) {
        if (my_strcmp(instruction, exceptions[i]) == 0)
            return 1;
    }
    return 0;
}
