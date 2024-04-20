/*
** EPITECH PROJECT, 2022
** music.c
** File description:
** music.c
*/

#include "./include/my.h"

void sfmusic(struct utils *u, struct game *g)
{
    if (g->state == 1 && g->music == 0) {
        sfMusic_play(u->music);
        g->music = 1;
    }
    if (g->state == 2) {
        sfMusic_stop(u->music);
        g->music = 0;
    }
}
