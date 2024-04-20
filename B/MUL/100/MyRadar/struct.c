/*
** EPITECH PROJECT, 2022
** struct.c
** File description:
** struct.c
*/

#include "./include/my.h"

void struct_tower(struct tower *tower, struct utils *utils, int nb_tower,
int index_bis)
{
    tower[nb_tower].x = my_getfloat(utils->tab[index_bis + 1]);
    tower[nb_tower].y = my_getfloat(utils->tab[index_bis + 2]);
    tower[nb_tower].size = my_getfloat(utils->tab[index_bis + 3]);
}

void struct_plane(struct plane *plane, struct utils *utils, int nb_plane,
int index_bis)
{
    plane[nb_plane].start_x = my_getfloat(utils->tab[index_bis + 1]);
    plane[nb_plane].start_y = my_getfloat(utils->tab[index_bis + 2]);
    plane[nb_plane].end_x = my_getfloat(utils->tab[index_bis + 3]);
    plane[nb_plane].end_y = my_getfloat(utils->tab[index_bis + 4]);
    plane[nb_plane].speed = my_getfloat(utils->tab[index_bis + 5]);
    plane[nb_plane].takeoff = my_getfloat(utils->tab[index_bis + 6]);
}

int struct_matrix(struct tower *tower, struct plane *plane,
struct utils *utils)
{
    int nb_tower = 0;
    int nb_plane = 0;
    int index_bis = 0;

    if (struct_matrix_errors(utils) == ERROR)
        return ERROR;

    while (nb_tower + nb_plane < utils->total_tower + utils->total_plane) {
        if (utils->tab[index_bis][0] == TOWER) {
            struct_tower(tower, utils, nb_tower, index_bis);
            nb_tower = nb_tower + 1;
            index_bis = index_bis + 4;
        }
        if (utils->tab[index_bis][0] == PLANE) {
            struct_plane(plane, utils, nb_plane, index_bis);
            nb_plane = nb_plane + 1;
            index_bis = index_bis + 7;
        }
    }
    return SUCCESS;
}
