/*
** EPITECH PROJECT, 2023
** long_zone
** File description:
** long_zone
*/

#include "rpg.h"

static void calcul_distance_bandit_player(window *win, int i)
{
    win->caracters.bandit[i].dy_total =
    win->caracters.player.y - win->caracters.bandit[i].position.y;
    if (win->caracters.player.x > win->caracters.bandit[i].position.x)
        win->caracters.bandit[i].dx =
        win->caracters.player.x - win->caracters.bandit[i].position.x;
    if (win->caracters.player.x < win->caracters.bandit[i].position.x)
        win->caracters.bandit[i].dx =
        win->caracters.bandit[i].position.x - win->caracters.player.x;
    if (win->caracters.player.y > win->caracters.bandit[i].position.y)
        win->caracters.bandit[i].dy =
        win->caracters.player.y - win->caracters.bandit[i].position.y;
    if (win->caracters.player.y < win->caracters.bandit[i].position.y)
        win->caracters.bandit[i].dy =
        win->caracters.bandit[i].position.y - win->caracters.player.y;
    if (win->caracters.bandit[i].dx <= 2 && win->caracters.bandit[i].dy <= 2)
        win->caracters.bandit[i].check = true;
    else
        win->caracters.bandit[i].check = false;
}

static void initialise_zone_bandit_view(window *win, int i)
{
    win->caracters.bandit[i].dx = 0;
    win->caracters.bandit[i].dy = 0;
    win->caracters.bandit[i].dy_total = 0;
    sfVector2f origin = {180.f, 170.f};
    sfCircleShape_setPosition(win->caracters.bandit[i].circle_view,
    sfSprite_getPosition(win->caracters.bandit[i].sprite));
    sfCircleShape_setOrigin(win->caracters.bandit[i].circle_view, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.bandit[i].circle_view, NULL);
    win->caracters.bandit[i].detection_view =
    sfCircleShape_getGlobalBounds(win->caracters.bandit[i].circle_view);
    if (sfFloatRect_contains(&win->caracters.bandit[i].detection_view,
    win->caracters.player.x, win->caracters.player.y)
    && win->caracters.bandit[i].isArround_view == false) {
        win->caracters.bandit[i].isArround_view = true;
    }
    calcul_distance_bandit_player(win, i);
}

void check_zone_bandit_view(window *win, int i)
{
    initialise_zone_bandit_view(win, i);
    if (win->caracters.bandit[i].isArround_view &&
    !win->caracters.bandit[i].check) {
        if (!sfFloatRect_contains(&win->caracters.bandit[i].detection_view,
            win->caracters.player.x, win->caracters.player.y)) {
            win->caracters.bandit[i].isArround_view = false;
        }
        if (move_bandit_diago(win, i) == 1)
            return;
        if (move_bandit_diago_two(win, i) == 1)
            return;
        if (move_bandit_left_right(win, i) == 1)
            return;
        if (move_bandit_frond_back(win, i) == 1)
            return;
    }
}
