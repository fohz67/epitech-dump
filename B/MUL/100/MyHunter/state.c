/*
** EPITECH PROJECT, 2022
** state.c
** File description:
** state.c
*/

#include "./include/my.h"

void sfdraw_menu(struct sprite *s, struct utils *u, struct game *g)
{
    sfVector2f scale = {0.4, 0.4};
    sfVector2f pos = {325, 350};

    sfSprite_setScale(s->sp_start, scale);
    sfSprite_setPosition(s->sp_start, pos);
    sfRenderWindow_drawSprite(u->window, s->sp_bg, NULL);
    sfRenderWindow_drawSprite(u->window, s->sp_start, NULL);

    sfVector2f pos2 = {260, 200};

    sfText_setString(g->text, LABEL_NAME);
    sfText_setFont(g->text, g->font);
    sfText_setCharacterSize(g->text, 80);
    sfText_setPosition(g->text, pos2);
    sfRenderWindow_drawText(u->window, g->text, NULL);
}

void sfdraw_game(struct sprite *s, struct utils *u,
struct game *g, struct vector *v)
{
    sfSprite_setTextureRect(s->sp_duck, u->rect);
    sfRenderWindow_drawSprite(u->window, s->sp_bg, NULL);
    sfRenderWindow_drawSprite(u->window, s->sp_duck, NULL);
    sfdraw_heart(s, u, g, v);
    sfscore(u, g);
}

void sfdraw_endgame2(struct utils *u, struct game *g)
{
    char str_score[64] = {0};
    itos((int) g->score, str_score, 10);

    sfVector2f pos = {360, 100};
    sfVector2f pos2 = {490, 190};

    sfText_setString(g->text, LABEL_SCORE);
    sfText_setFont(g->text, g->font);
    sfText_setCharacterSize(g->text, 80);
    sfText_setPosition(g->text, pos);
    sfRenderWindow_drawText(u->window, g->text, NULL);

    sfText_setString(g->text_score, str_score);
    sfText_setFont(g->text_score, g->font);
    sfText_setCharacterSize(g->text_score, 70);
    sfText_setPosition(g->text_score, pos2);
    sfRenderWindow_drawText(u->window, g->text_score, NULL);
}

void sfdraw_endgame(struct sprite *s, struct utils *u, struct game *g)
{
    sfVector2f scale = {0.4, 0.4};
    sfVector2f pos = {325, 350};

    sfSprite_setScale(s->sp_start, scale);
    sfSprite_setPosition(s->sp_start, pos);
    sfRenderWindow_drawSprite(u->window, s->sp_bg, NULL);
    sfRenderWindow_drawSprite(u->window, s->sp_start, NULL);

    sfdraw_endgame2(u, g);
}
