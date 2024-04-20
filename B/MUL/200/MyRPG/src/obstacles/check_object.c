/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_object.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "rpg.h"

int check_type_object(char c)
{
    char *type = "GWTSHPBcbthIiCEaA";

    for (int i = 0; type[i] != '\0'; i++) {
        if (c == type[i]) {
            return i;
        }
    }
    return -1;
}
