/*
** EPITECH PROJECT, 2022
** transcribe_picture.c
** File description:
** transcribe_picture.c
*/

#include "../include/my.h"

void display_picture(const struct st_pic *st_pic, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *final_buffer = NULL;

    final_buffer = malloc(sizeof(char *) * (size + 1));
    while (st_pic->array[i] != NULL) {
        while (st_pic->array[i][j] != '\0') {
            final_buffer[k] = st_pic->array[i][j];
            k = k + 1;
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    write(1, final_buffer, my_strlen(final_buffer));
    free(final_buffer);
}

int skip_comment_header(struct st_pic *st_pic, int i)
{
    while (st_pic->buffer[i] != '\0' && st_pic->buffer[i] != '\n') {
        my_putchar(st_pic->buffer[i]);
        i = i + 1;
    }
    my_putchar('\n');
    return i + 1;
}

int skip_header_picture(struct st_pic *st_pic)
{
    int i = 0;
    int j = 0;

    while (st_pic->buffer[i] != '\0' && j < 3) {
        if (st_pic->buffer[i] == '\n') {
            j++;
        }
        my_putchar(st_pic->buffer[i]);
        i++;
    }
    if (st_pic->buffer[i] == '#') {
        i = skip_comment_header(st_pic, i);
    }
    return i;
}

int malloc_picture(struct st_pic *st_pic)
{
    if ((st_pic->array = malloc(sizeof(char *) * (st_pic->size + 1))) == NULL) {
        return 84;
    }
    return 0;
}

int transcribe_picture(struct st_pic *st_pic)
{
    int i = 0;
    int j = 0;
    int nb = 0;

    if (malloc_picture(st_pic) == 84)
        return 84;
    i = skip_header_picture(st_pic);
    while (i < st_pic->size) {
        nb = st_pic->buffer[i];
        if (nb < 0) {
            nb = nb + 256;
        }
        st_pic->array[j] = my_strdup(my_strcat(my_itoa(nb, 10), "\n"));
        j = j + 1;
        i = i + 1;
    }
    st_pic->array[j] = NULL;
    display_picture(st_pic, j);
    free(st_pic->buffer);
    return 0;
}
