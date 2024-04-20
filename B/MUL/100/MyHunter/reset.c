/*
** EPITECH PROJECT, 2022
** reset.c
** File description:
** reset.c
*/

#include "./include/my.h"

void sfreset_duck(struct sprite *s)
{
    sfVector2f pos = {-110, rand() % 610};
    sfSprite_setPosition(s->sp_duck, pos);
}

void sfreset_game(struct game *g, struct vector *v)
{
    g->state = 1;
    g->life = 3;
    v->vector.x = 1;
    g->score = 0;
}
