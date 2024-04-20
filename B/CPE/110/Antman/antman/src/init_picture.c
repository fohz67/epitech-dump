/*
** EPITECH PROJECT, 2022
** init_picture.c
** File description:
** init_picture.c
*/

#include "../include/my.h"

int skip_comment_header(struct st_pic *st_pic, int i)
{
    while (st_pic->buffer[i] != '\0' && st_pic->buffer[i] != '\n') {
        st_pic->ascii[i] = st_pic->buffer[i];
        i = i + 1;
    }
    st_pic->ascii[i] = '\n';
    return i + 1;
}

int skip_header_picture(struct st_pic *st_pic)
{
    int i = 0;
    int j = 0;

    while (st_pic->buffer[i] != '\0' && j < 3) {
        if (st_pic->buffer[i] == '\n') {
            j = j + 1;
        }
        st_pic->ascii[i] = st_pic->buffer[i];
        i = i + 1;
    }
    if (st_pic->buffer[i] == '#') {
        i = skip_comment_header(st_pic, i);
    }
    return i;
}

int malloc_picture(struct st_pic *st_pic)
{
    if ((st_pic->ascii = malloc(sizeof(char *) * (st_pic->size + 1))) == NULL) {
        return 84;
    }
    st_pic->ascii[st_pic->size] = '\0';
    return 0;
}

int init_picture(struct st_pic *st_pic)
{
    int i = 0;
    int j = 0;
    int nb = 0;

    if (malloc_picture(st_pic) == 84) {
        return 84;
    }
    j = i = skip_header_picture(st_pic);
    while (i < st_pic->size) {
        nb = my_atoi(st_pic->buffer, i);
        st_pic->ascii[j] = nb;
        i = i + my_nbrlen(nb) + 1;
        j = j + 1;
    }
    write(1, st_pic->ascii, j);
    free(st_pic->buffer);
    free(st_pic->ascii);
    return 0;
}
