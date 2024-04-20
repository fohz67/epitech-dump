/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include "rpg.h"

static int update_game(window *win, map_t *map)
{
    if (win->state == 1 || win->state == 2) {
        sfMusic_stop(win->music.music[1]);
        display_back(win, map);
        update_all_sprite(win);
        update_music(win);
        display_map(win, map);
        if (update_pnj(win) == 84) {
            return 84;
        }
        display_health_bar(win);
        update_level(win);
        check_xp(win);
        if (win->state == 1) {
            update_story(win);
        } else {
            update_view(win);
        }
    }
    return 0;
}

static int update_all2(window *win)
{
    if (win->state == 5) {
        update_menu_game(win);
    }
    if (win->state == 3) {
        update_settings(win);
    }
    if (win->state == 6) {
        update_characteristics(win);
        update_inventory(win);
    }
    return 0;
}

int update_all(window *win, map_t *map)
{
    if (win->state == 0) {
        sfMusic_pause(win->music.music[0]);
        update_menu(win);
    }
    if (update_game(win, map) == 84) {
        return 84;
    }
    update_all2(win);
    return 0;
}
