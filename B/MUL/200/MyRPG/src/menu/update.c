/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include <stdbool.h>
#include "rpg.h"

static void position(window *win, int i, int align)
{
    sfVector2f position_text = {0, 0};
    sfVector2f position_title = {0, 0};
    sfVector2f position_button = win->menu.button[i].position;
    int text_width = sfText_getLocalBounds(win->menu.button[i].text).width;
    int text_height = sfText_getLocalBounds(win->menu.button[i].text).height;
    int title_width = sfText_getLocalBounds(win->menu.text).width;

    position_text.x = win->menu.button[i].position.x +
    win->menu.button[i].size.x / 2 - text_width / 2;
    position_text.y = win->menu.button[i].position.y +
    win->menu.button[i].size.y / 2 - text_height / 1.5 + align;
    position_title.x = 1920 / 2 - title_width / 2;
    position_title.y = 150;
    position_button.y += align;
    sfText_setPosition(win->menu.button[i].text, position_text);
    sfText_setPosition(win->menu.text, position_title);
    sfRectangleShape_setPosition(win->menu.button[i].button, position_button);
}

void update_menu(window *win)
{
    sfRenderWindow_drawSprite(win->window, win->background, NULL);
    for (int i = 0; i < menu_buttons; i++) {
        if (win->menu.button[i].isHover == true) {
            sfRenderWindow_drawRectangleShape(win->window,
            win->menu.button[i].button, NULL);
            sfRenderWindow_drawText(win->window,
            win->menu.button[i].text, NULL);
            position(win, i, 10);
        } else {
            sfRenderWindow_drawRectangleShape(win->window,
            win->menu.button[i].shadow, NULL);
            sfRenderWindow_drawRectangleShape(win->window,
            win->menu.button[i].button, NULL);
            sfRenderWindow_drawText(win->window,
            win->menu.button[i].text, NULL);
            position(win, i, 0);
        }
    }
    sfRenderWindow_drawText(win->window, win->menu.text, NULL);
}
