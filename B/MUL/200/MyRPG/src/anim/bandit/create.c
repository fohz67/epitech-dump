/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static const char bandit_sprite[] = "assets/img/sprite_bandit.png";

static void set_bandit_rect_two(window *win, int i)
{
    win->caracters.bandit[i].rect_att_left.top = 844;
    win->caracters.bandit[i].rect_att_left.left = 5;
    win->caracters.bandit[i].rect_att_left.width = 50;
    win->caracters.bandit[i].rect_att_left.height = 60;
    pos_bandit(win);
    win->caracters.bandit[i].speed = 30;
    win->caracters.bandit[i].vie = 60;
    win->caracters.bandit[i].isAttacking = false;
    win->caracters.bandit[i].death = false;
    win->caracters.bandit[i].timeElapsed = 0.0f;
    win->caracters.bandit[i].dx = 0;
    win->caracters.bandit[i].dy = 0;
    win->caracters.bandit[i].dy_total = 0;
}

static void set_bandit_rect(window *win, int i)
{
    win->caracters.bandit[i].rect_right.top = 715;
    win->caracters.bandit[i].rect_right.left = 12;
    win->caracters.bandit[i].rect_right.width = 50;
    win->caracters.bandit[i].rect_right.height = 60;
    win->caracters.bandit[i].rect_left.top = 588;
    win->caracters.bandit[i].rect_left.left = 17;
    win->caracters.bandit[i].rect_left.width = 60;
    win->caracters.bandit[i].rect_left.height = 60;
    win->caracters.bandit[i].rect_front.top = 651;
    win->caracters.bandit[i].rect_front.left = 17;
    win->caracters.bandit[i].rect_front.width = 50;
    win->caracters.bandit[i].rect_front.height = 60;
    win->caracters.bandit[i].rect_back.top = 523;
    win->caracters.bandit[i].rect_back.left = 17;
    win->caracters.bandit[i].rect_back.width = 50;
    win->caracters.bandit[i].rect_back.height = 60;
    set_bandit_rect_two(win, i);
}

static void create_circle_attack(window *win, int i)
{
    sfVector2f position = {win->caracters.bandit[i].position.x,
    win->caracters.bandit[i].position.y};
    sfVector2f scale = {0.6, 0.6};

    win->caracters.bandit[i].circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.bandit[i].circle, 50.f);
    sfCircleShape_setFillColor(win->caracters.bandit[i].circle, sfTransparent);
    sfSprite_setTexture(win->caracters.bandit[i].sprite,
    win->caracters.bandit[i].texture, sfTrue);
    sfSprite_setPosition(win->caracters.bandit[i].sprite, position);
    sfSprite_setScale(win->caracters.bandit[i].sprite, scale);
    sfSprite_setTextureRect(win->caracters.bandit[i].sprite,
    win->caracters.bandit[i].rect_right);
}

static void create_circle_view(window *win, int i)
{
    win->caracters.bandit[i].circle_view = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.bandit[i].circle_view, 200.f);
    sfCircleShape_setFillColor(win->caracters.bandit[i].circle_view,
    sfTransparent);
}

int create_animation_bandit(window *win)
{
    for (int i = 0; i < 10; i++) {
        set_bandit_rect(win, i);
        win->caracters.bandit[i].texture =
        sfTexture_createFromFile(bandit_sprite, NULL);
        if (win->caracters.bandit[i].texture == NULL) {
            return 84;
        }
        win->caracters.bandit[i].sprite = sfSprite_create();
        win->caracters.bandit[i].clock = sfClock_create();
        win->caracters.bandit[i].clock_anim = sfClock_create();
        win->caracters.bandit[i].clock_attack = sfClock_create();
        win->caracters.bandit[i].clock_anim_attack = sfClock_create();
        create_circle_attack(win, i);
        create_circle_view(win, i);
    }
    return 0;
}
