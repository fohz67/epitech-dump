/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "rpg.h"

static const char path[] = "assets/img/health_bar.png";

int create_health_bar(window *win)
{
    win->health.bar = sfSprite_create();
    win->health.texture = sfTexture_createFromFile(path, NULL);
    if (win->health.texture == NULL) {
        return 84;
    }
    win->health.rect.top = 49;
    win->health.rect.left = 0;
    win->health.rect.width = 430;
    win->health.rect.height = 75;
    sfSprite_setTexture(win->health.bar, win->health.texture, sfTrue);
    sfSprite_setScale(win->health.bar, (sfVector2f){0.4, 0.4});
    sfSprite_setTextureRect(win->health.bar, win->health.rect);
    return 0;
}
