/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "lib.h"

static int loop_event(window *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (manage_window(win) == 42) {
            return 42;
        }
        event_key_f(win, &win->event);
    }
    return 0;
}

static int loop(window *win, map_t *map)
{
    sfMusic_play(win->music.music[1]);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        if (loop_event(win) == 42) {
            return 0;
        }
        mouse_hover(win);
        update_all(win, map);
        sfRenderWindow_display(win->window);
    }
    return 0;
}

int main(int ac, char**)
{
    window win;
    map_t *map = NULL;

    if (ac != 1) {
        return 84;
    }
    if (malloc_all(&win) == 84) {
        return 84;
    }
    if (create_all(&win, &map) == 84) {
        return 84;
    }
    if (loop(&win, map) == 84) {
        return 84;
    }
    destroy_all(&win);
    return 0;
}
