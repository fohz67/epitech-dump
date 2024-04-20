/*
** EPITECH PROJECT, 2022
** dispatch.c
** File description:
** dispatch.c
*/

#include "../include/my.h"

int check_buffer(const char **av, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic)
{
    int nb = my_getnbr(av[2]);

    if (nb == 1 && my_strlen(st_dic->buffer) == 0) {
        return 84;
    }
    if (nb == 2 && my_strlen(st_html->buffer) == 0) {
        return 84;
    }
    if (nb == 3 && my_strlen(st_pic->buffer) == 0) {
        return 84;
    }
    return 0;
}

int put_buffer(const char **av, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic)
{
    int nb = my_getnbr(av[2]);

    if (nb == 1 && (st_dic->buffer = file_content(av[1], st_dic, st_html,
    st_pic)) == NULL) {
        return 84;
    }
    if (nb == 2 && (st_html->buffer = file_content(av[1], st_dic, st_html,
    st_pic)) == NULL) {
        return 84;
    }
    if (nb == 3 && (st_pic->buffer = file_content(av[1], st_dic, st_html,
    st_pic)) == NULL) {
        return 84;
    }
    return 0;
}

int dispatch(const char **av, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic)
{
    int nb = my_getnbr(av[2]);

    if (put_buffer(av, st_dic, st_html, st_pic) == 84 || nb < 1 || nb > 3) {
        return 84;
    }
    if (check_buffer(av, st_dic, st_html, st_pic) == 84) {
        return 0;
    }
    if (nb == 1 && init_dictionnary(st_dic) == 84) {
        return 84;
    }
    if (nb == 2 && init_html(st_html) == 84) {
        return 84;
    }
    if (nb == 3 && init_picture(st_pic) == 84) {
        return 84;
    }
    return 0;
}
