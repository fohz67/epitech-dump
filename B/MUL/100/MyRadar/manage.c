/*
** EPITECH PROJECT, 2022
** manage.c
** File description:
** manage.c
*/

#include "./include/my.h"

void key_pressed(sfEvent event, struct utils *utils)
{
    if (event.key.code == sfKeyL) {
        if (utils->shape_visible == 0) {
            utils->shape_visible = 1;
        } else {
            utils->shape_visible = 0;
        }
    }
    if (event.key.code == sfKeyS) {
        if (utils->sprite_visible == 0) {
            utils->sprite_visible = 1;
        } else {
            utils->sprite_visible = 0;
        }
    }
}

void manage_window(sfRenderWindow *window, sfEvent event, struct utils *utils)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtKeyReleased) {
            key_pressed(event, utils);
        }
    }
}
