/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

void destroy_towers(struct tower *tower, struct utils *utils)
{
    int index = 0;

    sfTexture_destroy(tower->t);

    while (index < utils->total_tower) {
        sfSprite_destroy(tower[index].sprite);
        sfCircleShape_destroy(tower[index].circle);
        index = index + 1;
    }
}

void destroy_plane(struct plane *plane, struct utils *utils)
{
    int index = 0;

    sfTexture_destroy(plane->t);

    while (index < utils->total_plane) {
        sfSprite_destroy(plane[index].sprite);
        sfRectangleShape_destroy(plane[index].rect);
        index = index + 1;
    }
}

void destroy_background(struct utils *utils, sfRenderWindow *window)
{
    sfSprite_destroy(utils->background);
    sfTexture_destroy(utils->texture);
    sfClock_destroy(utils->clock);
    sfRenderWindow_destroy(window);
}

int destroy_all(struct tower *tower, struct plane *plane,
struct utils *utils, sfRenderWindow *window)
{
    if (utils->total_tower > 0) {
        destroy_towers(tower, utils);
    }
    if (utils->total_plane > 0) {
        destroy_plane(plane, utils);
    }
    destroy_background(utils, window);
    return SUCCESS;
}
