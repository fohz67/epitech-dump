/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "lib.h"

static void destroy_settings(window *win)
{
    sfCircleShape_destroy(win->settings.slider.selector);
    sfRectangleShape_destroy(win->settings.slider.background);
    sfRectangleShape_destroy(win->settings.slider.shadow);
    for (int i = 0; i < settings_buttons; i++) {
        sfRectangleShape_destroy(win->settings.button[i].button);
        sfRectangleShape_destroy(win->settings.button[i].shadow);
        sfText_destroy(win->settings.button[i].text);
    }
    for (int i = 0; i < 5; i++) {
        sfText_destroy(win->settings.text[i]);
    }
    free(win->menu_game.text);
    free(win->settings.button);
}

static void destroy_menus(window *win)
{
    for (int i = 0; i < menu_buttons; i++) {
        sfRectangleShape_destroy(win->menu_game.button[i].button);
        sfRectangleShape_destroy(win->menu_game.button[i].shadow);
        sfText_destroy(win->menu_game.button[i].text);
    }
    free(win->menu_game.button);
    for (int i = 0; i < menu_buttons; i++) {
        sfRectangleShape_destroy(win->menu.button[i].button);
        sfRectangleShape_destroy(win->menu.button[i].shadow);
        sfText_destroy(win->menu.button[i].text);
    }
    sfText_destroy(win->menu.text);
    free(win->menu.button);
    for (int i = 0; i < 8; i++) {
        sfTexture_destroy(win->map_texture.texture[i]);
    }
    my_free_array(win->map_texture.map_back);
    my_free_array(win->map_texture.map_front);
}

static void destroy_gameplay(window *win)
{
    sfMusic_destroy(win->music.music[0]);
    sfMusic_destroy(win->music.music[1]);
    free(win->music.music);
    sfTexture_destroy(win->health.texture);
    sfSprite_destroy(win->health.bar);
    for (int i = 0; i < win->collid_nb; i++) {
        sfRectangleShape_destroy(win->collid[i].rect);
    }
    free(win->collid);
    sfTexture_destroy(win->story.texture);
    sfRectangleShape_destroy(win->story.rect);
    sfText_destroy(win->story.text);
}

void destroy_all(window *win)
{
    destroy_gameplay(win);
    destroy_menus(win);
    destroy_settings(win);
    destroy_caracters(win);
    destroy_inv(win);
    destroy_window(win);
}
