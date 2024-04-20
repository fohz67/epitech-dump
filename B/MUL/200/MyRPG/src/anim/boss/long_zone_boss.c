/*
** EPITECH PROJECT, 2023
** long_zone
** File description:
** long_zone
*/

#include "rpg.h"

static void calcul_distance_boss_player(window *win)
{
    win->caracters.boss.dy_total = win->caracters.player.y
    - win->caracters.boss.position.y;
    if (win->caracters.player.x > win->caracters.boss.position.x)
        win->caracters.boss.dx = win->caracters.player.x
        - win->caracters.boss.position.x;
    if (win->caracters.player.x < win->caracters.boss.position.x)
        win->caracters.boss.dx = win->caracters.boss.position.x
        - win->caracters.player.x;
    if (win->caracters.player.y > win->caracters.boss.position.y)
        win->caracters.boss.dy = win->caracters.player.y
        - win->caracters.boss.position.y;
    if (win->caracters.player.y < win->caracters.boss.position.y)
        win->caracters.boss.dy = win->caracters.boss.position.y
        - win->caracters.player.y;
    if (win->caracters.boss.dx <= 2 && win->caracters.boss.dy <= 2)
        win->caracters.boss.check = true;
    else
        win->caracters.boss.check = false;
}

static void initialise_zone_boss_view(window *win)
{
    win->caracters.boss.dx = 0;
    win->caracters.boss.dy = 0;
    win->caracters.boss.dy_total = 0;
    sfVector2f origin = {180.f, 170.f};
    sfCircleShape_setPosition(win->caracters.boss.circle_view,
    sfSprite_getPosition(win->caracters.boss.sprite));
    sfCircleShape_setOrigin(win->caracters.boss.circle_view, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.boss.circle_view, NULL);
    win->caracters.boss.detection_view =
    sfCircleShape_getGlobalBounds(win->caracters.boss.circle_view);
    if (sfFloatRect_contains(&win->caracters.boss.detection_view,
    win->caracters.player.x, win->caracters.player.y)
    && win->caracters.boss.isArround_view == false) {
        win->caracters.boss.isArround_view = true;
        sfClock_restart(win->caracters.boss.clock_dialogue);
    }
}

static int print_dialogue_boss(window *win)
{
    if (win->caracters.boss.isArround_view && !win->caracters.boss.isEnter) {
        sfTime elapsed_time =
        sfClock_getElapsedTime(win->caracters.boss.clock_dialogue);
        sfVector2f position = {win->caracters.player.x - 120,
        win->caracters.player.y + 60};
        if (sfTime_asSeconds(elapsed_time) < 5) {
            sfRenderWindow_drawSprite(win->window, win->caracters.boss.dialog,
            NULL);
            sfSprite_setPosition(win->caracters.boss.dialog, position);
        } else {
            win->caracters.player.speed = 4;
            win->caracters.boss.isEnter = true;
        }
    } return 0;
}

void check_zone_boss_view(window *win)
{
    initialise_zone_boss_view(win);
    calcul_distance_boss_player(win);
    if (win->caracters.boss.isArround_view && !win->caracters.boss.check) {
        if (!sfFloatRect_contains(&win->caracters.boss.detection_view,
        win->caracters.player.x, win->caracters.player.y)) {
            win->caracters.boss.isArround_view = false;
        }
        print_dialogue_boss(win);
        if (move_boss_diago(win) == 1)
            return;
        if (move_boss_diago_two(win) == 1)
            return;
        if (move_boss_left_right(win) == 1)
            return;
        if (move_boss_frond_back(win) == 1)
            return;
    }
}
