/*
** EPITECH PROJECT, 2023
** updae
** File description:
** update
*/

#include "rpg.h"
#include "lib.h"

void update_boss(window *win)
{
    sfVector2f pos_origin = {-10.f, 45.f};

    check_zone_boss(win);
    check_zone_boss_view(win);
    sfSprite_setOrigin(win->caracters.boss.sprite, pos_origin);
    if (win->caracters.boss.restart_clock) {
        sfClock_restart(win->caracters.boss.clock);
        sfClock_restart(win->caracters.boss.clock_anim);
        sfClock_restart(win->caracters.boss.clock_attack);
        sfClock_restart(win->caracters.boss.clock_anim_attack);
        sfClock_restart(win->caracters.boss.clock_dialogue);
        win->caracters.boss.restart_clock = false;
    }
    if (!win->caracters.boss.death)
        sfRenderWindow_drawSprite(win->window,
        win->caracters.boss.sprite, NULL);
}
