/*
** EPITECH PROJECT, 2022
** transcribe_html.c
** File description:
** transcribe_html.c
*/

#include "../include/my.h"

int transcribe_html(struct st_html *st_html)
{
    write(1, st_html->buffer, st_html->size);
    free(st_html->buffer);
    return 0;
}
