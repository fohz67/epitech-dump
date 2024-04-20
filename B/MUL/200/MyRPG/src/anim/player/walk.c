/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** walk.c
*/

#include <stdlib.h>
#include "rpg.h"

void walk_right_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.player.clock));
    if (time > 0.1) {
        time = 0;
        win->caracters.player.rect_right.left += 64;
        if (win->caracters.player.rect_right.left >= 550)
            win->caracters.player.rect_right.left = 18;
        sfClock_restart(win->caracters.player.clock);
    }
    sfSprite_setTextureRect(win->caracters.player.sprite,
    win->caracters.player.rect_right);
}

void walk_left_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(sfClock_getElapsedTime(
    win->caracters.player.clock));
    if (time > 0.1) {
        time = 0;
        win->caracters.player.rect_left.left += 64;
        if (win->caracters.player.rect_left.left >= 540) {
            win->caracters.player.rect_left.left = 12;
        }
        sfClock_restart(win->caracters.player.clock);
    }
    sfSprite_setTextureRect(win->caracters.player.sprite,
    win->caracters.player.rect_left);
}

void walk_front_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(sfClock_getElapsedTime(
    win->caracters.player.clock));
    if (time > 0.1) {
        time = 0;
        win->caracters.player.rect_front.left += 64;
        if (win->caracters.player.rect_front.left >= 550)
            win->caracters.player.rect_front.left = 17;
        sfClock_restart(win->caracters.player.clock);
    }
    sfSprite_setTextureRect(win->caracters.player.sprite,
    win->caracters.player.rect_front);
}

void walk_back_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(sfClock_getElapsedTime(
    win->caracters.player.clock));
    if (time > 0.1) {
        time = 0;
        win->caracters.player.rect_back.left += 64;
        if (win->caracters.player.rect_back.left >= 550)
            win->caracters.player.rect_back.left = 17;
        sfClock_restart(win->caracters.player.clock);
    }
    sfSprite_setTextureRect(win->caracters.player.sprite,
    win->caracters.player.rect_back);
}
