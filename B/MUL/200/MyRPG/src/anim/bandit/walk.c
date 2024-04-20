/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** walk.c
*/

#include <stdlib.h>
#include "rpg.h"

void walk_left_bandit_animation(window *win, int i)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.bandit[i].clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.bandit[i].rect_left.left += 64;
        if (win->caracters.bandit[i].rect_left.left >= 550) {
            win->caracters.bandit[i].rect_left.left = 12;
        }
        sfClock_restart(win->caracters.bandit[i].clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.bandit[i].sprite,
    win->caracters.bandit[i].rect_left);
}

void walk_right_bandit_animation(window *win, int i)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.bandit[i].clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.bandit[i].rect_right.left += 64;
        if (win->caracters.bandit[i].rect_right.left >= 550) {
            win->caracters.bandit[i].rect_right.left = 17;
        }
        sfClock_restart(win->caracters.bandit[i].clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.bandit[i].sprite,
    win->caracters.bandit[i].rect_right);
}

void walk_front_bandit_animation(window *win, int i)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.bandit[i].clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.bandit[i].rect_front.left += 64;
        if (win->caracters.bandit[i].rect_front.left >= 550) {
            win->caracters.bandit[i].rect_front.left = 12;
        }
        sfClock_restart(win->caracters.bandit[i].clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.bandit[i].sprite,
    win->caracters.bandit[i].rect_front);
}

void walk_back_bandit_animation(window *win, int i)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.bandit[i].clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.bandit[i].rect_back.left += 64;
        if (win->caracters.bandit[i].rect_back.left >= 550) {
            win->caracters.bandit[i].rect_back.left = 12;
        }
        sfClock_restart(win->caracters.bandit[i].clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.bandit[i].sprite,
    win->caracters.bandit[i].rect_back);
}

void attack_left_bandit(window *win, int i)
{
    sfTime elapsed_time =
    sfClock_getElapsedTime(win->caracters.bandit[i].clock_anim_attack);

    if (win->caracters.bandit[i].attack_frame_count < 6
    && sfTime_asSeconds(elapsed_time) > 0.14) {
        win->caracters.bandit[i].rect_att_left.left += 64;
        if (win->caracters.bandit[i].rect_att_left.left >= 365) {
            win->caracters.bandit[i].rect_att_left.left = 5;
        }
        win->caracters.bandit[i].attack_frame_count++;
        sfClock_restart(win->caracters.bandit[i].clock_anim_attack);
        sfSprite_setTextureRect(win->caracters.bandit[i].sprite,
        win->caracters.bandit[i].rect_att_left);
    } else if (win->caracters.bandit[i].attack_frame_count >= 6) {
        win->caracters.player.vie -= 10;
        win->health.rect.top += 80;
        sfSprite_setTextureRect(win->health.bar,
        win->health.rect);
        win->caracters.bandit[i].attack_frame_count = 0;
    }
}
