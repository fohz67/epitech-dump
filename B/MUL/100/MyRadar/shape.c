/*
** EPITECH PROJECT, 2022
** shape.c
** File description:
** shape.c
*/

#include "./include/my.h"

void shape_rectangle_shape(struct plane *plane, int index)
{
    float x = plane[index].start_x;
    float y = plane[index].start_y;

    sfVector2f pos_rect = {x - 10, y - 10};
    sfVector2f size_rect = {20, 20};

    sfRectangleShape_setPosition(plane[index].rect, pos_rect);
    sfRectangleShape_setSize(plane[index].rect, size_rect);
    sfRectangleShape_setFillColor(plane[index].rect, sfTransparent);
    sfRectangleShape_setOutlineColor(plane[index].rect, sfYellow);
    sfRectangleShape_setOutlineThickness(plane[index].rect, 3);
}

void shape_circle_tower(struct tower *tower, int index)
{
    float pourcentage = (tower[index].size / 100) * 1920;
    float x = tower[index].x - pourcentage;
    float y = tower[index].y - pourcentage;

    sfVector2f pos_circle = {x, y};

    sfCircleShape_setPosition(tower[index].circle, pos_circle);
    sfCircleShape_setRadius(tower[index].circle, pourcentage);
    sfCircleShape_setOutlineColor(tower[index].circle, sfCyan);
    sfCircleShape_setFillColor(tower[index].circle, sfTransparent);
    sfCircleShape_setOutlineThickness(tower[index].circle, 3);
}
