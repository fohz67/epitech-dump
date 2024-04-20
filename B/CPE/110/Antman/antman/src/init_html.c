/*
** EPITECH PROJECT, 2022
** init_html.c
** File description:
** init_html.c
*/

#include "../include/my.h"

int init_html(struct st_html *st_html)
{
    write(1, st_html->buffer, st_html->size);
    free(st_html->buffer);
    return 0;
}
