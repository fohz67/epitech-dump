/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** upgrade_level.c
*/

#include "rpg.h"

int check_xp(window *win)
{
    update_xp(win);
    if (win->characteristics.exp >= win->characteristics.exp_max) {
        win->characteristics.exp = 0;
        win->characteristics.exp_max += 5;
        win->characteristics.lvl += 1;
        win->characteristics.health += 5;
        win->characteristics.attack += 3;
        win->characteristics.defense += 2;
        update_stat(win);
    }
    return 0;
}
