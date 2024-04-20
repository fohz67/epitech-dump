/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-eddy.gardes
** File description:
** all_moves_bandit
*/

#include "rpg.h"

int move_bandit_diago(window *win, int i)
{
    if (win->caracters.bandit[i].dx > 2 &&
        win->caracters.player.x > win->caracters.bandit[i].position.x &&
        win->caracters.player.y > win->caracters.bandit[i].position.y) {
            win->caracters.bandit[i].position.x += 0.75;
            win->caracters.bandit[i].position.y += 0.75;
            walk_right_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
        }
    if (win->caracters.bandit[i].dx > 2 &&
        win->caracters.player.x < win->caracters.bandit[i].position.x &&
        win->caracters.player.y > win->caracters.bandit[i].position.y) {
            win->caracters.bandit[i].position.x -= 0.75;
            win->caracters.bandit[i].position.y += 0.75;
            walk_left_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
    } return 0;
}

int move_bandit_diago_two(window *win, int i)
{
    if (win->caracters.bandit[i].dx > 2 &&
        win->caracters.player.x < win->caracters.bandit[i].position.x &&
        win->caracters.player.y < win->caracters.bandit[i].position.y) {
            win->caracters.bandit[i].position.x -= 0.75;
            win->caracters.bandit[i].position.y -= 0.75;
            walk_left_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
        }
    if (win->caracters.bandit[i].dx > 2 &&
        win->caracters.player.x > win->caracters.bandit[i].position.x &&
        win->caracters.player.y < win->caracters.bandit[i].position.y) {
            win->caracters.bandit[i].position.x += 0.75;
            win->caracters.bandit[i].position.y -= 0.75;
            walk_right_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
    } return 0;
}

int move_bandit_left_right(window *win, int i)
{
    if (win->caracters.bandit[i].dx > 2 &&
        win->caracters.player.x >= win->caracters.bandit[i].position.x) {
            win->caracters.bandit[i].position.x += 0.75;
            walk_right_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
        }
    if (win->caracters.bandit[i].dx > 2 &&
        win->caracters.player.x <= win->caracters.bandit[i].position.x) {
            win->caracters.bandit[i].position.x -= 0.75;
            walk_left_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
    }
    return 0;
}

int move_bandit_frond_back(window *win, int i)
{
    if (win->caracters.bandit[i].dy_total < 1 &&
        win->caracters.player.y <= win->caracters.bandit[i].position.y) {
            win->caracters.bandit[i].position.y -= 0.75;
            walk_back_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
        }
    if (win->caracters.bandit[i].dy_total > -2 &&
        win->caracters.player.y >= win->caracters.bandit[i].position.y) {
            win->caracters.bandit[i].position.y += 0.75;
            walk_front_bandit_animation(win, i);
            sfSprite_setPosition(win->caracters.bandit[i].sprite,
            win->caracters.bandit[i].position);
            return 1;
    }
    return 0;
}
