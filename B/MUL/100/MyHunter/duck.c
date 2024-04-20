/*
** EPITECH PROJECT, 2022
** duck.c
** File description:
** duck.c
*/

#include "./include/my.h"

void sfduck_position(struct sprite *s, struct game *g)
{
    g->min_duck_x = sfSprite_getPosition(s->sp_duck).x;
    g->min_duck_y = sfSprite_getPosition(s->sp_duck).y;
    g->max_duck_x = sfSprite_getPosition(s->sp_duck).x + 110;
    g->max_duck_y = sfSprite_getPosition(s->sp_duck).y + 110;
}

void sfduck_animation(struct sprite *s, struct utils *u,
struct game *g, struct vector *v)
{
    sfVector2f scale = {1, 1};
    float sec = sfClock_getElapsedTime(u->clock).microseconds / 1000000.0;
    sfduck_position(s, g);
    sfSprite_setScale(s->sp_duck, scale);

    if (g->min_duck_x > 1080) {
        if ((g->life = g->life - 1) == 0)
            g->state = 2;
        sfreset_duck(s);
    }
    if (sec > 0.0)
        sfSprite_move(s->sp_duck, v->vector);
    if (sec > 0.12)
        u->rect.left = 0;
    if (sec > 0.24)
        u->rect.left = 110;
    if (sec > 0.36) {
        u->rect.left = 220;
        sfClock_restart(u->clock);
    }
}
