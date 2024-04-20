/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw.c
*/

#include "./include/my.h"

void draw_sprites(struct tower *tower, struct plane *plane,
struct utils *utils, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, utils->background, NULL);
    for (int i = 0; i < utils->total_tower || i < utils->total_plane; i++) {
        if (i < utils->total_tower && utils->sprite_visible == 0) {
            sfRenderWindow_drawSprite(window, tower[i].sprite, NULL);
        }
        if (i < utils->total_tower && utils->shape_visible == 0) {
            sfRenderWindow_drawCircleShape(window, tower[i].circle, NULL);
        }
        if (i < utils->total_plane && utils->sprite_visible == 0 &&
        plane[i].finish == 0) {
            sfRenderWindow_drawSprite(window, plane[i].sprite, NULL);
        }
        if (i < utils->total_plane && utils->shape_visible == 0 &&
        plane[i].finish == 0) {
            sfRenderWindow_drawRectangleShape(window, plane[i].rect, NULL);
        }
    }
}
