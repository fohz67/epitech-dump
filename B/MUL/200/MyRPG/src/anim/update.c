/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include <stdlib.h>
#include "rpg.h"

void update_all_sprite(window *win)
{
    update_player(win);
    update_bandit(win);
    update_boss(win);
}
