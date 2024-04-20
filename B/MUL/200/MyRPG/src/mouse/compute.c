/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** compute_click.c
*/

#include <stdbool.h>
#include "rpg.h"

void compute_menu(window *win, int i)
{
    if (i == 0) {
        win->state = 1;
    }
    if (i == 1) {
    }
    if (i == 2) {
        win->settings.state = win->state;
        win->state = 3;
    }
    if (i == 3) {
        sfRenderWindow_close(win->window);
    }
}

static void compute_settings2(window *win, int i)
{
    if (i == 4) {
        sfRenderWindow_destroy(win->window);
        win->window = create_renderwindow(1024, 640, 32, sfResize);
        win->caracters.player.speed = 3;
    }
    if (i == 5) {
        sfRenderWindow_destroy(win->window);
        win->window = create_renderwindow(960, 540, 32, sfResize);
        win->caracters.player.speed = 3;
    }
}

void compute_settings(window *win, int i)
{
    if (i == 0) {
        win->state = win->settings.state;
    }
    if (i == 1) {
        sfRenderWindow_destroy(win->window);
        win->window = create_renderwindow(1920, 1080, 32, sfFullscreen);
        win->caracters.player.speed = 3;
    }
    if (i == 2) {
        sfRenderWindow_destroy(win->window);
        win->window = create_renderwindow(1920, 1080, 32, sfResize);
        win->caracters.player.speed = 3;
    }
    if (i == 3) {
        sfRenderWindow_destroy(win->window);
        win->window = create_renderwindow(1366, 768, 32, sfResize);
        win->caracters.player.speed = 3;
    }
    compute_settings2(win, i);
}

void compute_menu_game(window *win, int i)
{
    if (i == 0) {
        win->state = 2;
        sfView_zoom(win->view, 0.35);
    }
    if (i == 1) {
        win->state = 6;
    }
    if (i == 2) {
        win->settings.state = win->state;
        win->state = 3;
    }
    if (i == 3) {
    }
    if (i == 4) {
        sfMusic_play(win->music.music[1]);
        view_player(win);
        win->state = 0;
    }
}
