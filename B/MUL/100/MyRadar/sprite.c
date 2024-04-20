/*
** EPITECH PROJECT, 2022
** sprite.c
** File description:
** sprite.c
*/

#include "./include/my.h"

int create_background(struct utils *utils)
{
    sfTexture *texture = sfTexture_createFromFile("./src/background.png", NULL);
    sfClock *clock = sfClock_create();

    if (texture) {
        utils->background = sfSprite_create();
        utils->texture = texture;
        utils->clock = clock;
        sfSprite_setTexture(utils->background, utils->texture, sfFalse);
        return SUCCESS;
    }
    return ERROR;
}

int create_planes(struct plane *plane, struct utils *utils)
{
    int index = 0;
    sfTexture *texture = sfTexture_createFromFile("./src/plane.png", NULL);

    if (texture) {
        while (index < utils->total_plane) {
            sfVector2f pos = {plane[index].start_x - 10,
            plane[index].start_y - 10};
            plane[index].sprite = sfSprite_create();
            plane[index].t = texture;
            plane[index].finish = 0;
            plane[index].safe = 0;
            plane[index].rect = sfRectangleShape_create();
            shape_rectangle_shape(plane, index);
            sfSprite_setTexture(plane[index].sprite, plane[index].t, sfFalse);
            sfSprite_setPosition(plane[index].sprite, pos);
            index++;
        }
        return SUCCESS;
    }
    return ERROR;
}

int create_towers(struct tower *tower, struct utils *utils)
{
    int index = 0;
    sfTexture *texture = sfTexture_createFromFile("./src/tower.png", NULL);

    if (texture) {
        while (index < utils->total_tower) {
            sfVector2f pos_sprite = {tower[index].x - 17.5,
            tower[index].y - 17.5};
            tower[index].sprite = sfSprite_create();
            tower[index].t = texture;
            tower[index].circle = sfCircleShape_create();

            shape_circle_tower(tower, index);
            sfSprite_setTexture(tower[index].sprite, tower[index].t, sfFalse);
            sfSprite_setPosition(tower[index].sprite, pos_sprite);
            index++;
        }
        return SUCCESS;
    }
    return ERROR;
}

int create_all(struct tower *tower, struct plane *plane,
struct utils *utils)
{
    int result_tower = 0;
    int result_plane = 0;
    int result_background = 0;

    result_tower = create_towers(tower, utils);
    result_plane = create_planes(plane, utils);
    result_background = create_background(utils);

    if (result_tower + result_plane + result_background >= ERROR) {
        write(1, BAD_RES, my_strlen(BAD_RES));
        return ERROR;
    }
    return SUCCESS;
}
