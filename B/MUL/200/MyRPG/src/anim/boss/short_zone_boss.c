/*
** EPITECH PROJECT, 2023
** short_zone
** File description:
** short_zoneù
*/

#include "rpg.h"

static void initialise_zone_boss(window *win)
{
    sfVector2f origin = {40.f, 35.f};

    sfCircleShape_setPosition(win->caracters.boss.circle,
    sfSprite_getPosition(win->caracters.boss.sprite));
    sfCircleShape_setOrigin(win->caracters.boss.circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.boss.circle, NULL);
    win->caracters.boss.detection =
    sfCircleShape_getGlobalBounds(win->caracters.boss.circle);
    if (sfFloatRect_contains(&win->caracters.boss.detection,
    win->caracters.player.x, win->caracters.player.y)
    && win->caracters.boss.isArround == false) {
        win->caracters.boss.isArround = true;
        win->caracters.boss.attack_frame_count = 0;
        sfClock_restart(win->caracters.boss.clock_attack);
    }
}

static void check_event_zone_boss(window *win)
{
    win->caracters.boss.elapsed =
    sfClock_getElapsedTime(win->caracters.boss.clock_attack);
    win->caracters.boss.timeElapsed =
    sfTime_asSeconds(win->caracters.boss.elapsed);
    if (win->caracters.boss.isAttacking && !win->caracters.boss.death) {
        win->caracters.boss.vie -= win->characteristics.attack_total;
        win->caracters.boss.isAttacking = false;
    }
    if (win->caracters.boss.vie <= 0 && !win->caracters.boss.death) {
        win->caracters.boss.death = true;
    }
    if (win->caracters.boss.check && win->caracters.boss.isArround &&
    !win->caracters.boss.death) {
        attack_left_boss(win);
    }
}

static void check_isplayer_dead_boss(window *win)
{
    if (win->characteristics.health <= 0) {
        win->caracters.player.x = 1400;
        win->caracters.player.y = 1245;
        sfSprite_setPosition(win->caracters.player.sprite,
        (sfVector2f){win->caracters.player.x, win->caracters.player.y});
        win->caracters.player.vie = win->characteristics.health;
        win->caracters.boss.vie = 500;
        win->health.rect.top = 49;
        sfSprite_setTextureRect(win->health.bar,
        win->health.rect);
    }
}

void check_zone_boss(window *win)
{
    initialise_zone_boss(win);
    if (win->caracters.boss.isArround == true) {
        check_event_zone_boss(win);
        check_isplayer_dead_boss(win);
    }
    if (!sfFloatRect_contains(&win->caracters.boss.detection,
    win->caracters.player.x, win->caracters.player.y)) {
        win->caracters.boss.isAttacking = false;
        win->caracters.boss.isArround = false;
        sfClock_restart(win->caracters.boss.clock_attack);
    }
}
