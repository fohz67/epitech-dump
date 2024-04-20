/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include "rpg.h"

void display_health_bar(window *win)
{
    sfVector2f position = {win->caracters.player.x - 350,
    win->caracters.player.y - 180};

    if (win->state == 2) {
        sfRenderWindow_drawSprite(win->window, win->health.bar, NULL);
        sfSprite_setPosition(win->health.bar, position);
    }
}
