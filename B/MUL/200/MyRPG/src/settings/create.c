/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static const char *settings_string[] = {
    "Back","Fullscreen","Windowed", "1366 x 768", "1024 x 640", "960 x 540"
};

static const sfVector2f settings_pos[] = {
    {1600, 900}, {300, 300}, {600, 300}, {400, 450}, {650, 450}, {900, 450},
    {300, 750}
};

static void attributes(window *win, int i)
{
    sfText_setFont(win->settings.button[i].text, win->font);
    sfText_setString(win->settings.button[i].text, settings_string[i]);
}

static void color(window *win, int i)
{
    sfColor color_btn = {61, 61, 61, 255};
    sfColor color_text = {255, 255, 255, 200};
    sfColor color_shadow = {35, 35, 35, 255};

    sfRectangleShape_setFillColor(win->settings.button[i].button, color_btn);
    sfRectangleShape_setFillColor(win->settings.button[i].shadow, color_shadow);
    sfRectangleShape_setFillColor(win->settings.slider.background, color_btn);
    sfRectangleShape_setFillColor(win->settings.slider.shadow, color_shadow);
    sfText_setFillColor(win->settings.button[i].text, color_text);
    sfText_setOutlineColor(win->settings.button[i].text, sfBlack);
    sfCircleShape_setOutlineColor(win->settings.slider.selector, sfBlack);
    sfCircleShape_setFillColor(win->settings.slider.selector, sfWhite);
}

static void position(window *win, int i)
{
    win->settings.button[i].position = settings_pos[i];
    win->settings.button[i].position_shadow = settings_pos[i];
    win->settings.button[i].position_shadow.y += 10;
    win->settings.slider.position = settings_pos[6];
    win->settings.slider.position_shadow = settings_pos[6];
    win->settings.slider.position_shadow.y += 10;
    win->settings.slider.position_selector = settings_pos[6];
    win->settings.slider.position_selector.y += 5;
    win->settings.slider.position_selector.x += 500;
    sfRectangleShape_setPosition(win->settings.button[i].button,
    win->settings.button[i].position);
    sfRectangleShape_setPosition(win->settings.button[i].shadow,
    win->settings.button[i].position_shadow);
    sfRectangleShape_setPosition(win->settings.slider.background,
    win->settings.slider.position);
    sfRectangleShape_setPosition(win->settings.slider.shadow,
    win->settings.slider.position_shadow);
    win->settings.slider.position.y += 5;
    sfCircleShape_setPosition(win->settings.slider.selector,
    win->settings.slider.position_selector);
}

static void size(window *win, int i)
{
    win->settings.button[i].size = (sfVector2f) {200, 50};
    win->settings.slider.size = (sfVector2f) {1000, 50};

    sfRectangleShape_setSize(win->settings.button[i].button,
    win->settings.button[i].size);
    sfRectangleShape_setSize(win->settings.button[i].shadow,
    win->settings.button[i].size);
    sfRectangleShape_setSize(win->settings.slider.background,
    win->settings.slider.size);
    sfRectangleShape_setSize(win->settings.slider.shadow,
    win->settings.slider.size);
    sfText_setCharacterSize(win->settings.button[i].text, 35);
    sfText_setOutlineThickness(win->settings.button[i].text, 2);
    sfCircleShape_setRadius(win->settings.slider.selector, 20);
    sfCircleShape_setOutlineThickness(win->settings.slider.selector, 3);
}

int create_settings(window *win)
{
    win->settings.slider.background = sfRectangleShape_create();
    win->settings.slider.shadow = sfRectangleShape_create();
    win->settings.slider.selector = sfCircleShape_create();
    for (int i = 0; i < settings_buttons; i++) {
        win->settings.button[i].button = sfRectangleShape_create();
        win->settings.button[i].shadow = sfRectangleShape_create();
        win->settings.button[i].text = sfText_create();
        for (int i = 0; i < 5; i++) {
            win->settings.text[i] = sfText_create();
        }
        size(win, i);
        color(win, i);
        attributes(win, i);
        position(win, i);
    }
    attributes_text(win);
    color_text(win);
    size_text(win);
    return 0;
}
