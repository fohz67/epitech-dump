/*
** EPITECH PROJECT, 2023
** walk
** File description:
** walk
*/

#include "rpg.h"

void attack_left_boss(window *win)
{
    sfTime elapsed_time =
    sfClock_getElapsedTime(win->caracters.boss.clock_anim_attack);

    if (win->caracters.boss.attack_frame_count < 6
    && sfTime_asSeconds(elapsed_time) > 0.11) {
        win->caracters.boss.rect_att_left.left += 64;
        if (win->caracters.boss.rect_att_left.left >= 365) {
            win->caracters.boss.rect_att_left.left = 5;
        }
        win->caracters.boss.attack_frame_count++;
        sfClock_restart(win->caracters.boss.clock_anim_attack);
        sfSprite_setTextureRect(win->caracters.boss.sprite,
        win->caracters.boss.rect_att_left);
    } else if (win->caracters.boss.attack_frame_count >= 6) {
        win->caracters.player.vie -= 10;
        win->health.rect.top += 80;
        sfSprite_setTextureRect(win->health.bar,
        win->health.rect);
        win->caracters.boss.attack_frame_count = 0;
    }
}

void walk_front_boss_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.boss.clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.boss.rect_front.left += 64;
        if (win->caracters.boss.rect_front.left >= 550) {
            win->caracters.boss.rect_front.left = 12;
        }
        sfClock_restart(win->caracters.boss.clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.boss.sprite,
    win->caracters.boss.rect_front);
}

void walk_back_boss_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.boss.clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.boss.rect_back.left += 64;
        if (win->caracters.boss.rect_back.left >= 550) {
            win->caracters.boss.rect_back.left = 12;
        }
        sfClock_restart(win->caracters.boss.clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.boss.sprite,
    win->caracters.boss.rect_back);
}

void walk_left_boss_animation(window *win)
{
    float time = 0.0f;

    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.boss.clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.boss.rect_left.left += 64;
        if (win->caracters.boss.rect_left.left >= 550) {
            win->caracters.boss.rect_left.left = 12;
        }
        sfClock_restart(win->caracters.boss.clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.boss.sprite,
    win->caracters.boss.rect_left);
}

void walk_right_boss_animation(window *win)
{
    float time = 0.0f;
    time = sfTime_asSeconds(
    sfClock_getElapsedTime(win->caracters.boss.clock_anim));
    if (time > 0.1) {
        time = 0;
        win->caracters.boss.rect_right.left += 64;
        if (win->caracters.boss.rect_right.left >= 550)
            win->caracters.boss.rect_right.left = 17;
        sfClock_restart(win->caracters.boss.clock_anim);
    }
    sfSprite_setTextureRect(win->caracters.boss.sprite,
    win->caracters.boss.rect_right);
}
