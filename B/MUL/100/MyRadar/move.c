/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move.c
*/

#include "./include/my.h"

sfVector2f get_position(struct plane *plane, int index)
{
    float x = 0;
    float y = 0;

    x = sfSprite_getPosition(plane[index].sprite).x;
    y = sfSprite_getPosition(plane[index].sprite).y;

    sfVector2f position = {x, y};
    return position;
}

sfVector2f get_vector(struct plane *plane, int index)
{
    float distance_x = 0;
    float distance_y = 0;
    float abs_x = 0;
    float abs_y = 0;
    float vector_x = 0;
    float vector_y = 0;

    distance_x = plane[index].end_x - plane[index].start_x;
    distance_y = plane[index].end_y - plane[index].start_y;
    abs_x = my_abs(distance_x);
    abs_y = my_abs(distance_y);
    vector_x = distance_x * plane[index].speed / (abs_x + abs_y);
    vector_y = distance_y * plane[index].speed / (abs_x + abs_y);

    sfVector2f vector = {vector_x, vector_y};
    return vector;
}

void move_sprites(struct tower *tower, struct plane *plane, struct utils *utils)
{
    float sc = sfClock_getElapsedTime(utils->clock).microseconds / 1000000.0;
    int index = 0;

    while (index < utils->total_plane) {
        intersections(tower, plane, utils, index);
        intersections_plane(plane, utils, index);

        sfVector2f vector_dir = get_vector(plane, index);

        if (sc > 0.01 && plane[index].finish == 0) {
            sfSprite_move(plane[index].sprite, vector_dir);
            sfRectangleShape_move(plane[index].rect, vector_dir);
            sfClock_restart(utils->clock);
        }
        index = index + 1;
    }
}
