/*
** EPITECH PROJECT, 2023
** short_zone
** File description:
** short_zone
*/

#include "rpg.h"

static void initialise_zone_bandit(window *win, int i)
{
    sfVector2f origin = {40.f, 35.f};

    sfCircleShape_setPosition(win->caracters.bandit[i].circle,
    sfSprite_getPosition(win->caracters.bandit[i].sprite));
    sfCircleShape_setOrigin(win->caracters.bandit[i].circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.bandit[i].circle, NULL);
    win->caracters.bandit[i].detection =
    sfCircleShape_getGlobalBounds(win->caracters.bandit[i].circle);
    if (sfFloatRect_contains(&win->caracters.bandit[i].detection,
    win->caracters.player.x, win->caracters.player.y)
    && win->caracters.bandit[i].isArround == false) {
        win->caracters.bandit[i].isArround = true;
        win->caracters.bandit[i].attack_frame_count = 0;
        sfClock_restart(win->caracters.bandit[i].clock_attack);
    }
}

static void check_event_zone_bandit(window *win, int i)
{
    win->caracters.bandit[i].elapsed =
    sfClock_getElapsedTime(win->caracters.bandit[i].clock_attack);
    win->caracters.bandit[i].timeElapsed =
    sfTime_asSeconds(win->caracters.bandit[i].elapsed);
    if (win->caracters.bandit[i].isAttacking &&
    !win->caracters.bandit[i].death) {
        win->caracters.bandit[i].vie -= win->characteristics.attack_total;
        win->caracters.bandit[i].isAttacking = false;
    }
    if (win->caracters.bandit[i].vie <= 0 &&
    !win->caracters.bandit[i].death) {
        win->characteristics.exp += 5;
        win->caracters.bandit[i].death = true;
    }
    if (win->caracters.bandit[i].check &&
    win->caracters.bandit[i].isArround && !win->caracters.bandit[i].death) {
        attack_left_bandit(win, i);
    }
}

static void check_isplayer_dead(window *win, int i)
{
    if (win->caracters.player.vie == 0) {
        win->caracters.player.x = 1400;
        win->caracters.player.y = 1245;
        sfSprite_setPosition(win->caracters.player.sprite,
        (sfVector2f){win->caracters.player.x, win->caracters.player.y});
        win->caracters.player.vie = win->characteristics.health;
        win->caracters.bandit[i].vie = 80;
        win->health.rect.top = 49;
        sfSprite_setTextureRect(win->health.bar,
        win->health.rect);
    }
}

void check_zone_bandit(window *win, int i)
{
    initialise_zone_bandit(win, i);
    if (win->caracters.bandit[i].isArround == true) {
        check_event_zone_bandit(win, i);
        check_isplayer_dead(win, i);
    }
    if (!sfFloatRect_contains(&win->caracters.bandit[i].detection,
    win->caracters.player.x, win->caracters.player.y)) {
        win->caracters.bandit[i].isAttacking = false;
        win->caracters.bandit[i].isArround = false;
        sfClock_restart(win->caracters.bandit[i].clock_attack);
    }
}
