/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

void view_player(window *win)
{
    sfVector2f center = {win->caracters.player.x, win->caracters.player.y};
    sfVector2f size = {1920, 1080};

    win->view = sfView_create();
    sfView_setCenter(win->view, center);
    sfView_setSize(win->view, size);
    sfView_zoom(win->view, 0.35);
}
