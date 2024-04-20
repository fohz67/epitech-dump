/*
** EPITECH PROJECT, 2023
** update_bandit
** File description:
** update_bandit
*/

#include "rpg.h"
#include "lib.h"

void update_bandit(window *win)
{
    sfVector2f pos_origin = {-10.f, 45.f};

    for (int i = 0; i < 10; i++) {
        check_zone_bandit(win, i);
        check_zone_bandit_view(win, i);
        sfSprite_setOrigin(win->caracters.bandit[i].sprite, pos_origin);
        if (win->caracters.bandit[i].restart_clock) {
            sfClock_restart(win->caracters.bandit[i].clock);
            sfClock_restart(win->caracters.bandit[i].clock_anim);
            sfClock_restart(win->caracters.bandit[i].clock_attack);
            sfClock_restart(win->caracters.bandit[i].clock_anim_attack);
            win->caracters.bandit[i].restart_clock = false;
        }
        if (!win->caracters.bandit[i].death)
            sfRenderWindow_drawSprite(win->window,
            win->caracters.bandit[i].sprite, NULL);
        }
}

void pos_bandit(window *win)
{
    win->caracters.bandit[0].position.x = 3300;
    win->caracters.bandit[0].position.y = 1690;
    win->caracters.bandit[1].position.x = 3300;
    win->caracters.bandit[1].position.y = 1845;
    win->caracters.bandit[2].position.x = 3200;
    win->caracters.bandit[2].position.y = 1945;
    win->caracters.bandit[3].position.x = 2000;
    win->caracters.bandit[3].position.y = 6550;
    win->caracters.bandit[4].position.x = 2100;
    win->caracters.bandit[4].position.y = 6500;
    win->caracters.bandit[5].position.x = 2300;
    win->caracters.bandit[5].position.y = 6500;
    win->caracters.bandit[6].position.x = 2400;
    win->caracters.bandit[6].position.y = 6550;
    win->caracters.bandit[7].position.x = 2500;
    win->caracters.bandit[7].position.y = 6600;
    win->caracters.bandit[8].position.x = 3900;
    win->caracters.bandit[8].position.y = 6600;
    win->caracters.bandit[9].position.x = 3800;
    win->caracters.bandit[9].position.y = 6600;
}
