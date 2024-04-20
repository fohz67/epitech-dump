/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-eddy.gardes
** File description:
** update_player
*/

#include "rpg.h"

static void update_move_diag_anim_player(window *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) &&
    sfKeyboard_isKeyPressed(sfKeyS)
    && !win->caracters.player.isAttack)
        walk_front_animation(win);
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
    sfKeyboard_isKeyPressed(sfKeyS)
    && !win->caracters.player.isAttack)
        walk_front_animation(win);
    if (sfKeyboard_isKeyPressed(sfKeyD) &&
    sfKeyboard_isKeyPressed(sfKeyZ)
    && !win->caracters.player.isAttack)
        walk_back_animation(win);
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
    sfKeyboard_isKeyPressed(sfKeyZ)
    && !win->caracters.player.isAttack)
        walk_back_animation(win);
    update_attack_anim_player(win);
}

static void update_move_animation_player2(window *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && !win->caracters.player.isAttack) {
        win->caracters.player.y += win->caracters.player.speed;
        win->caracters.player.d_click = sfFalse;
        win->caracters.player.q_click = sfFalse;
        win->caracters.player.s_click = sfTrue;
        win->caracters.player.z_click = sfFalse;
        win->key = sfKeyS;
        walk_front_animation(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && !win->caracters.player.isAttack) {
        win->caracters.player.y -= win->caracters.player.speed;
        win->caracters.player.d_click = sfFalse;
        win->caracters.player.q_click = sfFalse;
        win->caracters.player.s_click = sfFalse;
        win->caracters.player.z_click = sfTrue;
        win->key = sfKeyZ;
        walk_back_animation(win);
    }
}

static void update_move_animation_player(window *win)
{
    update_move_diag_anim_player(win);
    if (sfKeyboard_isKeyPressed(sfKeyD) && !win->caracters.player.isAttack) {
        win->caracters.player.x += win->caracters.player.speed;
        win->caracters.player.d_click = sfTrue;
        win->caracters.player.q_click = sfFalse;
        win->caracters.player.s_click = sfFalse;
        win->caracters.player.z_click = sfFalse;
        win->key = sfKeyD;
        walk_right_animation(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && !win->caracters.player.isAttack) {
        win->caracters.player.x -= win->caracters.player.speed;
        win->caracters.player.d_click = sfFalse;
        win->caracters.player.q_click = sfTrue;
        win->caracters.player.s_click = sfFalse;
        win->caracters.player.z_click = sfFalse;
        win->key = sfKeyQ;
        walk_left_animation(win);
    }
    update_move_animation_player2(win);
}

void update_player(window *win)
{
    sfVector2f position = {0, 0};
    sfFloatRect fR;

    update_move_animation_player(win);
    for (int i = 0; i < win->collid_nb; i++) {
        fR = sfRectangleShape_getGlobalBounds(win->collid[i].rect);
        if (sfFloatRect_contains(&fR, (float)win->caracters.player.x,
        (float)win->caracters.player.y)) {
            update_collision(win);
            return;
        }
    }
    position.x = win->caracters.player.x;
    position.y = win->caracters.player.y;
    sfSprite_setPosition(win->caracters.player.sprite, position);
    sfRenderWindow_drawSprite(win->window,
    win->caracters.player.sprite, NULL);
}
