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
    sfVector2f position_button = win->settings.button[i].position;
    int text_width =
    sfText_getLocalBounds(win->settings.button[i].text).width;
    int text_height =
    sfText_getLocalBounds(win->settings.button[i].text).height;

    position_text.x = win->settings.button[i].position.x +
    win->settings.button[i].size.x / 2 - text_width / 2;
    position_text.y = win->settings.button[i].position.y +
    win->settings.button[i].size.y / 2 - text_height / 1.5 + align;
    position_button.y += align;
    sfText_setPosition(win->settings.button[i].text, position_text);
    sfRectangleShape_setPosition(win->settings.button[i].button,
    position_button);
}

static void position_text(window *win)
{
    sfVector2f position_title = {0, 0};
    int title_width = sfText_getLocalBounds(win->settings.text[0]).width;

    position_title.x = 1920 / 2 - title_width / 2;
    position_title.y = 30;
    sfText_setPosition(win->settings.text[0], position_title);
    sfText_setPosition(win->settings.text[1], (sfVector2f){100, 100});
    sfText_setPosition(win->settings.text[2], (sfVector2f){100, 600});
    sfText_setPosition(win->settings.text[3], (sfVector2f){100, 300});
    sfText_setPosition(win->settings.text[4], (sfVector2f){100, 450});
}

static void update_buttons(window *win)
{
    for (int i = 0; i < settings_buttons; i++) {
        position_text(win);
        if (win->settings.button[i].isHover == true) {
            position(win, i, 10);
            sfRenderWindow_drawRectangleShape(win->window,
            win->settings.button[i].button, NULL);
            sfRenderWindow_drawText(win->window,
            win->settings.button[i].text, NULL);
        } else {
            position(win, i, 0);
            sfRenderWindow_drawRectangleShape(win->window,
            win->settings.button[i].shadow, NULL);
            sfRenderWindow_drawRectangleShape(win->window,
            win->settings.button[i].button, NULL);
            sfRenderWindow_drawText(win->window,
            win->settings.button[i].text, NULL);
        }
    }
}

void update_settings(window *win)
{
    sfRenderWindow_drawSprite(win->window, win->background, NULL);
    sfRenderWindow_drawRectangleShape(win->window,
    win->settings.slider.shadow, NULL);
    sfRenderWindow_drawRectangleShape(win->window,
    win->settings.slider.background, NULL);
    sfRenderWindow_drawCircleShape(win->window,
    win->settings.slider.selector, NULL);
    update_buttons(win);
    for (int i = 0; i < 5; i++) {
        sfRenderWindow_drawText(win->window, win->settings.text[i], NULL);
    }
}
