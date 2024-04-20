/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_attack.c
*/

#include "rpg.h"

static void condition_attack_front(window *win)
{
    sfTime elapsed_time = sfClock_getElapsedTime(win->caracters.player.clock);

    if (win->caracters.player.attack_frame_count < 6 &&
    sfTime_asSeconds(elapsed_time) > 0.1) {
        win->caracters.player.rect_att_back.left += 64;
        if (win->caracters.player.rect_att_back.left >= 385)
            win->caracters.player.rect_att_back.left = 17;
        win->caracters.player.attack_frame_count++;
        sfClock_restart(win->caracters.player.clock);
        sfSprite_setTextureRect(win->caracters.player.sprite,
        win->caracters.player.rect_att_back);
        return;
    }
    if (win->caracters.player.attack_frame_count >= 6) {
        win->caracters.player.isAttack = sfFalse;
        for (int i = 0; i < 10; i++) {
            win->caracters.bandit[i].isAttacking = true;
        }
        win->caracters.boss.isAttacking = true;
    }
}

static void condition_attack_back(window *win)
{
    sfTime elapsed_time = sfClock_getElapsedTime(win->caracters.player.clock);

    if (win->caracters.player.attack_frame_count < 6
    && sfTime_asSeconds(elapsed_time) > 0.1) {
        win->caracters.player.rect_att_front.left += 64;
        if (win->caracters.player.rect_att_front.left >= 385)
            win->caracters.player.rect_att_front.left = 17;
        win->caracters.player.attack_frame_count++;
        sfClock_restart(win->caracters.player.clock);
        sfSprite_setTextureRect(win->caracters.player.sprite,
        win->caracters.player.rect_att_front);
        return;
    }
    if (win->caracters.player.attack_frame_count >= 6) {
        win->caracters.player.isAttack = sfFalse;
        for (int i = 0; i < 10; i++) {
            win->caracters.bandit[i].isAttacking = true;
        }
        win->caracters.boss.isAttacking = true;
    }
}

static void condition_attack_left(window *win)
{
    sfTime elapsed_time = sfClock_getElapsedTime(win->caracters.player.clock);

    if (win->caracters.player.attack_frame_count < 6
    && sfTime_asSeconds(elapsed_time) > 0.1) {
        win->caracters.player.rect_att_left.left += 64;
        if (win->caracters.player.rect_att_left.left >= 365)
            win->caracters.player.rect_att_left.left = 5;
        win->caracters.player.attack_frame_count++;
        sfClock_restart(win->caracters.player.clock);
        sfSprite_setTextureRect(win->caracters.player.sprite,
        win->caracters.player.rect_att_left);
        return;
    }
    if (win->caracters.player.attack_frame_count >= 6) {
        win->caracters.player.isAttack = sfFalse;
        for (int i = 0; i < 10; i++) {
            win->caracters.bandit[i].isAttacking = true;
        }
        win->caracters.boss.isAttacking = true;
    }
}

void condition_attack_right(window *win)
{
    sfTime elapsed_time = sfClock_getElapsedTime(win->caracters.player.clock);

    if (win->caracters.player.attack_frame_count < 6
    && sfTime_asSeconds(elapsed_time) > 0.1) {
        win->caracters.player.rect_att_right.left += 64;
        if (win->caracters.player.rect_att_right.left >= 380)
            win->caracters.player.rect_att_right.left = 17;
        win->caracters.player.attack_frame_count++;
        sfClock_restart(win->caracters.player.clock);
        sfSprite_setTextureRect(win->caracters.player.sprite,
        win->caracters.player.rect_att_right);
        return;
    }
    if (win->caracters.player.attack_frame_count >= 6) {
        win->caracters.player.isAttack = sfFalse;
        for (int i = 0; i < 10; i++) {
            win->caracters.bandit[i].isAttacking = true;
        }
        win->caracters.boss.isAttacking = true;
    }
}

void update_attack_anim_player(window *win)
{
    if (sfMouse_isButtonPressed(sfMouseRight)
    && !win->caracters.player.isAttack) {
        win->caracters.player.isAttack = sfTrue;
        win->caracters.player.attack_frame_count = 0;
        win->caracters.boss.attack_frame_count = 0;
        sfClock_restart(win->caracters.player.clock);
    }
    if (win->caracters.player.isAttack &&
    win->caracters.player.d_click == sfTrue)
        condition_attack_right(win);
    if (win->caracters.player.isAttack &&
    win->caracters.player.q_click == sfTrue)
        condition_attack_left(win);
    if (win->caracters.player.isAttack &&
    win->caracters.player.s_click == sfTrue)
        condition_attack_back(win);
    if (win->caracters.player.isAttack &&
    win->caracters.player.z_click == sfTrue)
        condition_attack_front(win);
}
