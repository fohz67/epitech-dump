/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** click.c
*/

#include <stdbool.h>
#include "rpg.h"

void mouse_click_selector(window *win)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(win->window);

    win->settings.slider.position_selector.x = cursor.x -15;
    win->music.vol = (win->settings.slider.position_selector.x -
    win->settings.slider.position.x) / 10;
    sfMusic_setVolume(win->music.music[0], win->music.vol);
    sfMusic_setVolume(win->music.music[1], win->music.vol);
    sfCircleShape_setPosition(win->settings.slider.selector,
    win->settings.slider.position_selector);
}

static void mouse_click_settings(window *win)
{
    for (int i = 0; i < settings_buttons; i++) {
        if (win->settings.button[i].isHover == true &&
        win->settings.button[i].isActivate == true) {
            win->settings.button[i].isClicked = true;
            compute_settings(win, i);
        }
    }
}

static void mouse_click_menu(window *win)
{
    activate_menu(win);
    for (int i = 0; i < menu_buttons; i++) {
        if (win->menu.button[i].isHover == true &&
        win->menu.button[i].isActivate == true) {
            win->menu.button[i].isClicked = true;
            compute_menu(win, i);
        }
    }
}

static void mouse_click_menu_game(window *win)
{
    activate_menu_game(win);
    for (int i = 0; i < menu_game_buttons; i++) {
        if (win->menu_game.button[i].isHover == true &&
        win->menu_game.button[i].isActivate == true) {
            win->menu_game.button[i].isClicked = true;
            compute_menu_game(win, i);
        }
    }
}

void mouse_click(window *win)
{
    mouse_click_menu(win);
    mouse_click_menu_game(win);
    mouse_click_settings(win);
    mouse_click_inventory(win);
}
