/*
** EPITECH PROJECT, 2022
** sprite.c
** File description:
** sprite.c
*/

#include "./include/my.h"

void sfdraw_heart(struct sprite *s, struct utils *u,
struct game *g, struct vector *v)
{
    sfVector2f scale = {0.13, 0.13};

    sfSprite_setPosition(s->sp_h1, g->life <= 0 ? v->posDead : v->pos1);
    sfSprite_setPosition(s->sp_h2, g->life <= 1 ? v->posDead : v->pos2);
    sfSprite_setPosition(s->sp_h3, g->life <= 2 ? v->posDead : v->pos3);

    sfSprite_setScale(s->sp_h1, scale);
    sfSprite_setScale(s->sp_h2, scale);
    sfSprite_setScale(s->sp_h3, scale);

    sfRenderWindow_drawSprite(u->window, s->sp_h1, NULL);
    sfRenderWindow_drawSprite(u->window, s->sp_h2, NULL);
    sfRenderWindow_drawSprite(u->window, s->sp_h3, NULL);
}

void sfdraw_sprites(struct sprite *s, struct utils *u,
struct game *g, struct vector *v)
{
    if (g->state == 0) {
        sfdraw_menu(s, u, g);
    }
    if (g->state == 1) {
        sfdraw_game(s, u, g, v);
    }
    if (g->state == 2) {
        sfdraw_endgame(s, u, g);
    }
    sfRenderWindow_drawSprite(u->window, s->sp_shot, NULL);
}

int sfset_sprites(struct sprite *s, struct utils *u, struct texture *t)
{
    sfRenderWindow_setFramerateLimit(u->window, 144);
    sfRenderWindow_setMouseCursorVisible(u->window, 0);

    if (!t->background || !t->spritesheet || !t->mouse || !t->heart
    || !t->start || !t->starthov)
        return 84;

    sfSprite_setTexture(s->sp_bg, t->background, sfFalse);
    sfSprite_setTexture(s->sp_duck, t->spritesheet, sfTrue);
    sfSprite_setTexture(s->sp_shot, t->mouse, sfTrue);
    sfSprite_setTexture(s->sp_h1, t->heart, sfTrue);
    sfSprite_setTexture(s->sp_h2, t->heart, sfTrue);
    sfSprite_setTexture(s->sp_h3, t->heart, sfTrue);
    sfSprite_setTexture(s->sp_start, t->start, sfTrue);
    sfVector2f pos = {-110, rand() % 610};
    sfSprite_setPosition(s->sp_duck, pos);
    return 0;
}
