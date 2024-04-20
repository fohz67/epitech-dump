/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-eddy.gardes
** File description:
** all_moves_boss
*/

#include "rpg.h"

int move_boss_diago(window *win)
{
    if (win->caracters.boss.dx > 2 &&
    win->caracters.player.x > win->caracters.boss.position.x &&
    win->caracters.player.y > win->caracters.boss.position.y) {
        win->caracters.boss.position.x += 0.75;
        win->caracters.boss.position.y += 0.75;
        walk_right_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    }
    if (win->caracters.boss.dx > 2 &&
    win->caracters.player.x < win->caracters.boss.position.x &&
    win->caracters.player.y > win->caracters.boss.position.y) {
        win->caracters.boss.position.x -= 0.75;
        win->caracters.boss.position.y += 0.75;
        walk_left_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    } return 0;
}

int move_boss_diago_two(window *win)
{
    if (win->caracters.boss.dx > 2 &&
    win->caracters.player.x < win->caracters.boss.position.x &&
    win->caracters.player.y < win->caracters.boss.position.y) {
        win->caracters.boss.position.x -= 0.75;
        win->caracters.boss.position.y -= 0.75;
        walk_left_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    }
    if (win->caracters.boss.dy > 2 &&
    win->caracters.player.x > win->caracters.boss.position.x &&
    win->caracters.player.y < win->caracters.boss.position.y) {
        win->caracters.boss.position.x += 0.75;
        win->caracters.boss.position.y -= 0.75;
        walk_right_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    } return 0;
}

int move_boss_left_right(window *win)
{
    if (win->caracters.boss.dx > 2 &&
    win->caracters.player.x >= win->caracters.boss.position.x) {
        win->caracters.boss.position.x += 0.75;
        walk_right_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    }
    if (win->caracters.boss.dx > 2 &&
    win->caracters.player.x <= win->caracters.boss.position.x) {
        win->caracters.boss.position.x -= 0.75;
        walk_left_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    } return 0;
}

int move_boss_frond_back(window *win)
{
    if (win->caracters.boss.dy_total < 1 &&
    win->caracters.player.y <= win->caracters.boss.position.y) {
        win->caracters.boss.position.y -= 0.75;
        walk_back_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    }
    if (win->caracters.boss.dy_total > -2 &&
    win->caracters.player.y >= win->caracters.boss.position.y) {
        win->caracters.boss.position.y += 0.75;
        walk_front_boss_animation(win);
        sfSprite_setPosition(win->caracters.boss.sprite,
        win->caracters.boss.position);
        return 1;
    } return 0;
}
