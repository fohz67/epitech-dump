/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include "rpg.h"

void update_view(window *win)
{
    sfVector2f center = {win->caracters.player.x, win->caracters.player.y};

    sfView_setCenter(win->view, center);
    sfRenderWindow_setView(win->window, win->view);
}

void reset_view(window *win)
{
    sfVector2f size_window = {1920, 1080};

    sfView_reset(win->view, (sfFloatRect){0, 0, 1920, 1090});
    sfView_setSize(win->view, size_window);
    sfRenderWindow_setView(win->window, win->view);
}
