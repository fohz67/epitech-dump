/*
** EPITECH PROJECT, 2022
** animation.c
** File description:
** animation.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "./include/my.h"

void sfanimation_button(struct sprite *s, struct game *g, sfVector2i cursor,
struct texture *t)
{
    if ((cursor.x >= 325) && (cursor.y >= 350) &&
    (cursor.x <= 725) && (cursor.y <= 510) &&
    (g->state == 0 || g->state == 2)) {
        sfSprite_setTexture(s->sp_start, t->starthov, sfTrue);
    } else {
        sfSprite_setTexture(s->sp_start, t->start, sfTrue);
    }
}

void sfanimation_cursor(struct sprite *s, struct game *g, sfVector2i cursor)
{
    sfVector2f pos = {cursor.x, cursor.y};
    sfVector2f pos2 = {cursor.x - 51, cursor.y - 51};

    if (g->state == 0) {
        sfSprite_setPosition(s->sp_shot, pos);
    } else {
        sfSprite_setPosition(s->sp_shot, pos2);
    }
}

void sfanimation(struct sprite *s, struct utils *u, struct game *g,
struct texture *t)
{
    sfVector2i cursor = sfMouse_getPosition((const sfWindow*) u->window);
    sfTime time = sfClock_getElapsedTime(u->clock);
    sfVector2f scale = {0.2, 0.2};

    float seconds = time.microseconds / 1000000.0;

    sfSprite_setScale(s->sp_shot, scale);

    if (seconds > 0.0) {
        sfanimation_button(s, g, cursor, t);
        sfanimation_cursor(s, g, cursor);
    }
}
