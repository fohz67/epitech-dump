/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** manage.c
*/

#include "rpg.h"

int manage_window(window *win)
{
    if (win->event.type == sfEvtClosed) {
        sfRenderWindow_close(win->window);
    }
    event_key_e(&win->event, win);
    event_key_escape(&win->event, win);
    if (update_event_story(win, &win->event) == 42) {
        return 42;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    win->settings.slider.isHover == true) {
        mouse_click_selector(win);
        return 0;
    }
    if (win->event.type == sfEvtMouseButtonPressed) {
        mouse_click(win);
    }
    return 0;
}
