/*
** EPITECH PROJECT, 2022
** intersections.c
** File description:
** intersections.c
*/

#include "./include/my.h"

void intersections(struct tower *tower, struct plane *plane,
struct utils *utils, int index)
{
    int index_tower = 0;
    int already = 0;

    while (index_tower < utils->total_tower) {
        sfVector2f pos = get_position(plane, index);
        float diff = my_pow((pos.x + 10 - tower[index_tower].x), 2) +
        my_pow((pos.y + 10 - tower[index_tower].y), 2);
        float sum = my_pow((10 + (tower[index_tower].size / 100) * 1920), 2);

        if (diff <= sum) {
            sfRectangleShape_setOutlineColor(plane[index].rect, sfGreen);
            plane[index].safe = 1;
            already = 1;
        }
        if (already == 0) {
            sfRectangleShape_setOutlineColor(plane[index].rect, sfYellow);
            plane[index].safe = 0;
        }
        index_tower = index_tower + 1;
    }
}

void intersections_plane(struct plane *plane,
struct utils *utils, int index)
{
    int index_plane = 0;
    sfVector2f pos2 = get_position(plane, index);

    while (index_plane < utils->total_plane) {
        sfVector2f pos = get_position(plane, index_plane);

        float diff = my_pow(pos.x - pos2.x, 2) + my_pow(pos.y - pos2.y, 2);
        float sum = my_pow(10 + 10, 2);

        if (diff <= sum && index != index_plane &&
        plane[index].safe == 0 && plane[index_plane].safe == 0) {
            plane[index].finish = 1;
            plane[index_plane].finish = 1;
        }
        index_plane = index_plane + 1;
    }
}
