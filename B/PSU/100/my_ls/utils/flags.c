/*
** EPITECH PROJECT, 2022
** flags.c
** File description:
** flags.c
*/

#include "../include/my.h"

void flags(char fchar, char *flag)
{
    int index = 1;

    if (fchar == 'a')
        flag[0] = 'y';
    if (fchar == 'l')
        flag[1] = 'y';
    if (fchar == 'R')
        flag[2] = 'y';
    if (fchar == 'd')
        flag[3] = 'y';
    if (fchar == 'r')
        flag[4] = 'y';
    if (fchar == 't')
        flag[5] = 'y';
}
