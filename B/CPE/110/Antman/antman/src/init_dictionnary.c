/*
** EPITECH PROJECT, 2022
** init_dictionnary.c
** File description:
** init_dictionnary.c
*/

#include "../include/my.h"

int init_dictionnary(struct st_dic *st_dic)
{
    write(1, st_dic->buffer, st_dic->size);
    free(st_dic->buffer);
    return 0;
}
