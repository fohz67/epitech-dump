/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static const char path[] = "assets/img/sprite_player.png";

static void set_rect_attack_player(window *win)
{
    win->caracters.player.rect_att_right.top = 972;
    win->caracters.player.rect_att_right.left = 21;
    win->caracters.player.rect_att_right.width = 50;
    win->caracters.player.rect_att_right.height = 60;
    win->caracters.player.rect_att_left.top = 844;
    win->caracters.player.rect_att_left.left = 5;
    win->caracters.player.rect_att_left.width = 50;
    win->caracters.player.rect_att_left.height = 60;
    win->caracters.player.rect_att_front.top = 907;
    win->caracters.player.rect_att_front.left = 17;
    win->caracters.player.rect_att_front.width = 50;
    win->caracters.player.rect_att_front.height = 60;
    win->caracters.player.rect_att_back.top = 780;
    win->caracters.player.rect_att_back.left = 17;
    win->caracters.player.rect_att_back.width = 50;
    win->caracters.player.rect_att_back.height = 60;
}

static void set_rect_player(window *win)
{
    win->caracters.player.vie = 50;
    win->caracters.player.rect_right.top = 716;
    win->caracters.player.rect_right.left = 18;
    win->caracters.player.rect_right.width = 50;
    win->caracters.player.rect_right.height = 60;
    win->caracters.player.rect_left.top = 588;
    win->caracters.player.rect_left.left = 12;
    win->caracters.player.rect_left.width = 50;
    win->caracters.player.rect_left.height = 60;
    win->caracters.player.rect_front.top = 651;
    win->caracters.player.rect_front.left = 17;
    win->caracters.player.rect_front.width = 50;
    win->caracters.player.rect_front.height = 60;
    win->caracters.player.rect_back.top = 523;
    win->caracters.player.rect_back.left = 17;
    win->caracters.player.rect_back.width = 50;
    win->caracters.player.rect_back.height = 60;
    set_rect_attack_player(win);
}

static void create_animation_player2(window *win)
{
    sfVector2f position = {win->caracters.player.x, win->caracters.player.y};
    sfVector2f scale = {0.6, 0.6};
    sfVector2f origin = {17, 46};

    sfSprite_setTexture(win->caracters.player.sprite,
    win->caracters.player.texture, sfTrue);
    sfSprite_setOrigin(win->caracters.player.sprite, origin);
    sfSprite_setPosition(win->caracters.player.sprite, position);
    sfSprite_setScale(win->caracters.player.sprite, scale);
    sfSprite_setTextureRect(win->caracters.player.sprite,
    win->caracters.player.rect_right);
}

int create_animation_player(window *win)
{
    set_rect_player(win);
    win->caracters.player.x = 1245;
    win->caracters.player.y = 1245;
    win->caracters.player.speed = 4;
    win->caracters.player.isAttack = sfFalse;
    win->caracters.player.texture = sfTexture_createFromFile(path, NULL);
    if (win->caracters.player.texture == NULL) {
        return 84;
    }
    win->caracters.player.sprite = sfSprite_create();
    win->caracters.player.clock = sfClock_create();
    create_animation_player2(win);
    return 0;
}
