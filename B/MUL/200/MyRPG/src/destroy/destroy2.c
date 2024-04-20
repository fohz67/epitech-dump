/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy2.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "lib.h"

void destroy_inv(window *win)
{
    sfText_destroy(win->inventory.text);
    sfSprite_destroy(win->characteristics.sprite);
    sfSprite_destroy(win->characteristics.back);
    sfTexture_destroy(win->characteristics.texture);
    sfTexture_destroy(win->characteristics.text_back);
    for (int i = 0; i < 6; i++) {
        sfText_destroy(win->characteristics.text[i]);
    }
    free(win->characteristics.text);
}

void destroy_window(window *win)
{
    sfView_destroy(win->view);
    sfSprite_destroy(win->background);
    sfTexture_destroy(win->texture);
    sfFont_destroy(win->font);
    sfRenderWindow_destroy(win->window);
}

void destroy_caracters2(window *win)
{
    for (int i = 0; i < 10; i++) {
        sfSprite_destroy(win->caracters.bandit[i].sprite);
        sfTexture_destroy(win->caracters.bandit[i].texture);
        sfClock_destroy(win->caracters.bandit[i].clock);
        sfClock_destroy(win->caracters.bandit[i].clock_anim);
        sfClock_destroy(win->caracters.bandit[i].clock_anim_attack);
        sfClock_destroy(win->caracters.bandit[i].clock_attack);
        sfCircleShape_destroy(win->caracters.bandit[i].circle);
        sfCircleShape_destroy(win->caracters.bandit[i].circle_view);
    }
    free(win->caracters.bandit);
}

void destroy_caracters(window *win)
{
    sfSprite_destroy(win->caracters.boss.sprite);
    sfTexture_destroy(win->caracters.boss.texture);
    sfClock_destroy(win->caracters.boss.clock);
    sfClock_destroy(win->caracters.boss.clock_anim);
    sfCircleShape_destroy(win->caracters.boss.circle);
    sfCircleShape_destroy(win->caracters.boss.circle_view);
    sfClock_destroy(win->caracters.boss.clock_attack);
    sfClock_destroy(win->caracters.boss.clock_anim_attack);
    sfSprite_destroy(win->caracters.forestboy.sprite);
    sfTexture_destroy(win->caracters.forestboy.texture);
    sfSprite_destroy(win->caracters.grandpa.sprite);
    sfTexture_destroy(win->caracters.grandpa.texture);
    sfCircleShape_destroy(win->caracters.grandpa.circle);
    sfSprite_destroy(win->caracters.woman.sprite);
    sfTexture_destroy(win->caracters.woman.texture);
    sfSprite_destroy(win->caracters.player.sprite);
    sfTexture_destroy(win->caracters.player.texture);
    sfClock_destroy(win->caracters.player.clock);
}
