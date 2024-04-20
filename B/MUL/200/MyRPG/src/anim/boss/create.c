/*
** EPITECH PROJECT, 2023
** create
** File description:
** create
*/

#include "rpg.h"

static const char boss_sprite[] = "assets/img/sprite_boss.png";

static void set_boss_rect_two(window *win)
{
    win->caracters.boss.rect_att_left.top = 844;
    win->caracters.boss.rect_att_left.left = 5;
    win->caracters.boss.rect_att_left.width = 50;
    win->caracters.boss.rect_att_left.height = 60;

    win->caracters.boss.position.x = 3850;
    win->caracters.boss.position.y = 6550;
    win->caracters.boss.speed = 30;
    win->caracters.boss.vie = 500;
    win->caracters.boss.isAttacking = false;
    win->caracters.boss.death = false;
    win->caracters.boss.timeElapsed = 0.0f;
    win->caracters.boss.dx = 0;
    win->caracters.boss.dy = 0;
    win->caracters.boss.dy_total = 0;
    win->caracters.boss.isEnter = false;
}

static void set_boss_rect(window *win)
{
    win->caracters.boss.rect_right.top = 715;
    win->caracters.boss.rect_right.left = 12;
    win->caracters.boss.rect_right.width = 50;
    win->caracters.boss.rect_right.height = 60;
    win->caracters.boss.rect_front.top = 651;
    win->caracters.boss.rect_front.left = 17;
    win->caracters.boss.rect_front.width = 50;
    win->caracters.boss.rect_front.height = 60;
    win->caracters.boss.rect_left.top = 588;
    win->caracters.boss.rect_left.left = 17;
    win->caracters.boss.rect_left.width = 60;
    win->caracters.boss.rect_left.height = 60;
    win->caracters.boss.rect_back.top = 523;
    win->caracters.boss.rect_back.left = 17;
    win->caracters.boss.rect_back.width = 50;
    win->caracters.boss.rect_back.height = 60;
    set_boss_rect_two(win);
}

static void create_circle_attack_boss(window *win)
{
    sfVector2f scale = {0.6, 0.6};

    win->caracters.boss.circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.boss.circle, 50.f);
    sfCircleShape_setFillColor(win->caracters.boss.circle, sfTransparent);
    sfSprite_setTexture(win->caracters.boss.sprite,
    win->caracters.boss.texture, sfTrue);
    sfSprite_setPosition(win->caracters.boss.sprite,
    win->caracters.boss.position);
    sfSprite_setScale(win->caracters.boss.sprite, scale);
    sfSprite_setTextureRect(win->caracters.boss.sprite,
    win->caracters.boss.rect_right);
}

static void create_circle_view_boss(window *win)
{
    win->caracters.boss.circle_view = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.boss.circle_view, 200.f);
    sfCircleShape_setFillColor(win->caracters.boss.circle_view, sfTransparent);
}

int create_animation_boss(window *win)
{
    set_boss_rect(win);
    create_dialog_boss(win);
    win->caracters.boss.texture =
    sfTexture_createFromFile(boss_sprite, NULL);
    if (win->caracters.boss.texture == NULL) {
        return 84;
    }
    win->caracters.boss.sprite = sfSprite_create();
    win->caracters.boss.clock = sfClock_create();
    win->caracters.boss.clock_anim = sfClock_create();
    win->caracters.boss.clock_attack = sfClock_create();
    win->caracters.boss.clock_anim_attack = sfClock_create();
    win->caracters.boss.clock_dialogue = sfClock_create();
    create_circle_attack_boss(win);
    create_circle_view_boss(win);
    return 0;
}
