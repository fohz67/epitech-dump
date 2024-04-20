/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** conditions_reg.c
*/

#include <stdlib.h>
#include "lib.h"
#include "asm.h"
#include "op.h"

int condition_full_reg(char **array, int max_args, int decal)
{
    for (int i = 1 + decal; i < max_args + 1; i++) {
        if (array[i][0] != 'r')
            return 84;
        array[i][0] = '0';
        if (array[i][my_strlen(array[i]) - 1] == ',')
            array[i][my_strlen(array[i]) - 1] = '\0';
        if (array[i][1] == '\0')
            return 84;
        if (my_isnbr(array[i]) == false)
            return 84;
        array[i][0] = 'r';
    }
    return 0;
}

int condition_full_dir(char **array, int max_args, int decal)
{
    for (int i = 1 + decal; i < max_args + 1; i++) {
        if (array[i][0] != '%' || my_strlen(array[i]) < 2)
            return 84;
    }
    return 0;
}
