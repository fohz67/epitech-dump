/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

int main(int ac, const char **av)
{
    struct st_dic st_dic;
    struct st_html st_html;
    struct st_pic st_pic;

    if (ac != 3) {
        return 84;
    }
    if (my_getnbr(av[2]) > 3 || my_getnbr(av[2]) < 1) {
        return 84;
    }
    if (dispatch(av, &st_dic, &st_html, &st_pic) == 84) {
        return 84;
    }
    return 0;
}
