/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_text.c
*/

#include "rpg.h"

void attributes_text(window *win)
{
    for (int i = 0; i < 5; i++) {
        sfText_setFont(win->settings.text[i], win->font);
    }
    sfText_setString(win->settings.text[0], "Settings");
    sfText_setString(win->settings.text[1], "Window");
    sfText_setString(win->settings.text[2], "Sound");
    sfText_setString(win->settings.text[3], "Mode :");
    sfText_setString(win->settings.text[4], "Resolution :");
}

void color_text(window *win)
{
    for (int i = 0; i < 5; i++) {
        sfText_setFillColor(win->settings.text[i], sfWhite);
        sfText_setOutlineColor(win->settings.text[i], sfBlack);
    }
}

void size_text(window *win)
{
    for (int i = 0; i < 3; i++) {
        sfText_setCharacterSize(win->settings.text[i], 100);
        sfText_setOutlineThickness(win->settings.text[i], 5);
    }
    for (int i = 3; i < 5; i++) {
        sfText_setCharacterSize(win->settings.text[i], 40);
        sfText_setOutlineThickness(win->settings.text[i], 5);
    }
}
