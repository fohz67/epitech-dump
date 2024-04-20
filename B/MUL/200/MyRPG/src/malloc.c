/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** malloc.c
*/

#include <stdlib.h>
#include "rpg.h"

static int malloc_all2(window *win)
{
    if ((win->music.music = malloc(sizeof(music) * 2)) == NULL) {
        return 84;
    }
    if ((win->characteristics.text = malloc(sizeof(characteristics)
    * 5)) == NULL) {
        return 84;
    }
    if ((win->caracters.bandit = malloc(sizeof(bandit)
    * 10)) == NULL) {
        return 84;
    }
    return 0;
}

int malloc_all(window *win)
{
    if ((win->menu.button = malloc(sizeof(button) * menu_buttons)) == NULL) {
        return 84;
    }
    if ((win->settings.button = malloc(sizeof(button_settings)
    * settings_buttons)) == NULL) {
        return 84;
    }
    if ((win->menu_game.button = malloc(sizeof(button_game)
    * menu_game_buttons)) == NULL) {
        return 84;
    }
    if ((win->settings.text = malloc(sizeof(settings) * 4)) == NULL) {
        return 84;
    }
    if ((malloc_all2(win)) == 84) {
        return 84;
    }
    return 0;
}
