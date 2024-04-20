/*
** EPITECH PROJECT, 2022
** score.c
** File description:
** score.c
*/

#include "./include/my.h"

void sfscore(struct utils *u, struct game *g)
{
    char str_score[64] = {0};
    itos((int) g->score, str_score, 10);

    sfVector2f pos = {20, 0};

    sfText_setString(g->text, str_score);
    sfText_setFont(g->text, g->font);
    sfText_setCharacterSize(g->text, 80);
    sfText_setPosition(g->text, pos);
    sfRenderWindow_drawText(u->window, g->text, NULL);
}
