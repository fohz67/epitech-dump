/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** activate.c
*/

#include "rpg.h"

void activate_menu(window *win)
{
    for (int i = 0; i < menu_buttons; i++) {
        if (win->state == 0) {
            win->menu.button[i].isActivate = true;
        } else {
            win->menu.button[i].isActivate = false;
        }
    }
    for (int i = 0; i < settings_buttons; i++) {
        if (win->state == 3) {
            win->settings.button[i].isActivate = true;
        } else {
            win->settings.button[i].isActivate = false;
        }
    }
}

void activate_menu_game(window *win)
{
    for (int i = 0; i < menu_game_buttons; i++) {
        if (win->state == 5) {
            win->menu_game.button[i].isActivate = true;
        } else {
            win->menu_game.button[i].isActivate = false;
        }
    }
}

void activate_inventory(window *win)
{
    for (box *tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        if (win->state == 6) {
            tmp->isActivate = true;
        } else {
            tmp->isActivate = false;
        }
    }
}
