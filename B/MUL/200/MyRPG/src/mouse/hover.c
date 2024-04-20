/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hover.c
*/

#include <stdbool.h>
#include "rpg.h"

static void mouse_hover_settings(window *win, sfVector2i cursor)
{
    sfFloatRect fR = {0};
    sfFloatRect fR2 = {0};

    for (int i = 0; i < settings_buttons; i++) {
        fR = sfRectangleShape_getGlobalBounds(win->settings.button[i].button);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
            win->settings.button[i].isHover = true;
        } else {
            win->settings.button[i].isHover = false;
        }
    }
    fR2 = sfRectangleShape_getGlobalBounds(win->settings.slider.background);
    if (sfFloatRect_contains(&fR2, cursor.x, cursor.y)) {
        win->settings.slider.isHover = true;
    } else {
        win->settings.slider.isHover = false;
    }
}

static void mouse_hover_menu(window *win, sfVector2i cursor)
{
    sfFloatRect fR = {0};

    for (int i = 0; i < menu_buttons; i++) {
        fR = sfRectangleShape_getGlobalBounds(win->menu.button[i].button);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
            win->menu.button[i].isHover = true;
        } else {
            win->menu.button[i].isHover = false;
        }
    }
}

static void mouse_hover_menu_game(window *win, sfVector2i cursor)
{
    sfFloatRect fR = {0};

    for (int i = 0; i < menu_game_buttons; i++) {
        fR = sfRectangleShape_getGlobalBounds(win->menu_game.button[i].button);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
            win->menu_game.button[i].isHover = true;
        } else {
            win->menu_game.button[i].isHover = false;
        }
    }
}

void mouse_hover_inventory(window *win, sfVector2i cursor)
{
    sfFloatRect fR = {0};

    for (box *tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        fR = sfRectangleShape_getGlobalBounds(tmp->rect);
        if (sfFloatRect_contains(&fR, cursor.x + 50, cursor.y + 20)) {
            tmp->isHover = true;
            sfRectangleShape_setOutlineColor(tmp->rect, sfYellow);
        } else {
            tmp->isHover = false;
            sfRectangleShape_setOutlineColor(tmp->rect, sfBlack);
        }
    }
}

void mouse_hover(window *win)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(win->window);

    mouse_hover_menu(win, cursor);
    mouse_hover_menu_game(win, cursor);
    mouse_hover_settings(win, cursor);
}
