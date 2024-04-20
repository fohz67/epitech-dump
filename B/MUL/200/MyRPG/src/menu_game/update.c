/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include "rpg.h"

static void position(window *win, int i, int align)
{
    sfVector2f position_text = {0, 0};
    sfVector2f position_title = {0, 0};
    sfVector2f position_button = win->menu_game.button[i].position;
    int text_width =
    sfText_getLocalBounds(win->menu_game.button[i].text).width;
    int text_height =
    sfText_getLocalBounds(win->menu_game.button[i].text).height;
    int title_width = sfText_getLocalBounds(win->menu_game.text).width;

    position_text.x = win->menu_game.button[i].position.x +
    win->menu_game.button[i].size.x / 2 - text_width / 2;
    position_text.y = win->menu_game.button[i].position.y +
    win->menu_game.button[i].size.y / 2 - text_height / 1.5 + align;
    position_title.x = 1920 / 2 - title_width / 2;
    position_title.y = 150;
    position_button.y += align;
    sfText_setPosition(win->menu_game.button[i].text, position_text);
    sfText_setPosition(win->menu_game.text, position_title);
    sfRectangleShape_setPosition
    (win->menu_game.button[i].button, position_button);
}

int event_key_escape(sfEvent *event, window *win)
{
    if (event->type == sfEvtKeyReleased &&
    event->key.code == sfKeyEscape && win->state == 2) {
        win->state = 5;
        reset_view(win);
    } else if (event->type == sfEvtKeyReleased &&
    event->key.code == sfKeyEscape && win->state == 5) {
        sfView_zoom(win->view, 0.35);
        win->state = 2;
    }
    return 0;
}

void update_menu_game(window *win)
{
    sfRenderWindow_drawSprite(win->window, win->background, NULL);
    for (int i = 0; i < menu_game_buttons; i++) {
        if (win->menu_game.button[i].isHover == true) {
            sfRenderWindow_drawRectangleShape(win->window,
            win->menu_game.button[i].button, NULL);
            sfRenderWindow_drawText(win->window,
            win->menu_game.button[i].text, NULL);
            position(win, i, 10);
        } else {
            sfRenderWindow_drawRectangleShape(win->window,
            win->menu_game.button[i].shadow, NULL);
            sfRenderWindow_drawRectangleShape(win->window,
            win->menu_game.button[i].button, NULL);
            sfRenderWindow_drawText(win->window,
            win->menu_game.button[i].text, NULL);
            position(win, i, 0);
        }
    }
    sfRenderWindow_drawText(win->window, win->menu_game.text, NULL);
}
