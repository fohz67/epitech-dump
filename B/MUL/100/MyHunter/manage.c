/*
** EPITECH PROJECT, 2022
** generate.c
** File description:
** generate.c
*/

#include "./include/my.h"

void sfmanage_click(struct sprite *s, struct game *g,
struct vector *v, sfVector2i cursor)
{
    if ((cursor.x >= g->min_duck_x) && (cursor.y >= g->min_duck_y) &&
    (cursor.x <= g->max_duck_x) && (cursor.y <= g->max_duck_y)) {
        v->vector.x = v->vector.x + 0.1;
        g->score = g->score + 1;
        sfreset_duck(s);
    }

    if ((cursor.x >= 325) && (cursor.y >= 350) &&
    (cursor.x <= 725) && (cursor.y <= 510) &&
    (g->state == 0 || g->state == 2)) {
        sfreset_game(g, v);
    }
}

void sfmanage(struct sprite *s, struct utils *u,
struct game *g, struct vector *v)
{
    sfVector2i cursor = sfMouse_getPosition((const sfWindow*) u->window);

    if (u->event.type == sfEvtClosed) {
        sfRenderWindow_close(u->window);
    }
    if (u->event.type == sfEvtMouseButtonPressed) {
        sfmanage_click(s, g, v, cursor);
        if (g->state == 1 && g->score > 0) {
            sfMusic_stop(u->gun);
            sfMusic_play(u->gun);
        }
    }
}
