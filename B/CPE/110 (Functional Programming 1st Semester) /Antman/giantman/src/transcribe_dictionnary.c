/*
** EPITECH PROJECT, 2022
** transcribe_dictionnary.c
** File description:
** transcribe_dictionnary.c
*/

#include "../include/my.h"

int transcribe_dictionnary(struct st_dic *st_dic)
{
    write(1, st_dic->buffer, st_dic->size);
    free(st_dic->buffer);
    return 0;
}
