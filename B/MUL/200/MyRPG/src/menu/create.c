/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "rpg.h"

static const char *menu_string[] = {
    "Start", "Resume", "Settings", "Exit"
};

static void attributes(window *win, int i)
{
    sfText_setFont(win->menu.button[i].text, win->font);
    sfText_setFont(win->menu.text, win->font);
    sfText_setString(win->menu.button[i].text, menu_string[i]);
    sfText_setString(win->menu.text, name);
}

static void color(window *win, int i)
{
    sfColor color_btn = {61, 61, 61, 255};
    sfColor color_shadow = {35, 35, 35, 255};
    sfColor color_text = {255, 255, 255, 200};

    sfRectangleShape_setFillColor(win->menu.button[i].button, color_btn);
    sfRectangleShape_setFillColor(win->menu.button[i].shadow, color_shadow);
    sfText_setFillColor(win->menu.button[i].text, color_text);
    sfText_setFillColor(win->menu.text, sfWhite);
    sfText_setOutlineColor(win->menu.button[i].text, sfBlack);
    sfText_setOutlineColor(win->menu.text, sfBlack);
}

static void position(window *win, int i)
{
    win->menu.button[i].position = (sfVector2f) {685, 400 + i * 130};
    win->menu.button[i].position_shadow =
    (sfVector2f) {685, 400 + i * 130 + 10};

    sfRectangleShape_setPosition(win->menu.button[i].button,
    win->menu.button[i].position);
    sfRectangleShape_setPosition(win->menu.button[i].shadow,
    win->menu.button[i].position_shadow);
}

static void size(window *win, int i)
{
    win->menu.button[i].size = (sfVector2f) {550, 100};

    sfRectangleShape_setSize(win->menu.button[i].button,
    win->menu.button[i].size);
    sfRectangleShape_setSize(win->menu.button[i].shadow,
    win->menu.button[i].size);
    sfText_setCharacterSize(win->menu.button[i].text, 35);
    sfText_setCharacterSize(win->menu.text, 100);
    sfText_setOutlineThickness(win->menu.button[i].text, 2);
    sfText_setOutlineThickness(win->menu.text, 5);
}

int create_menu(window *win)
{
    for (int i = 0; i < menu_buttons; i++) {
        win->menu.button[i].button = sfRectangleShape_create();
        win->menu.button[i].shadow = sfRectangleShape_create();
        win->menu.button[i].text = sfText_create();
        win->menu.text = sfText_create();
        size(win, i);
        position(win, i);
        color(win, i);
        attributes(win, i);
    }
    return 0;
}
