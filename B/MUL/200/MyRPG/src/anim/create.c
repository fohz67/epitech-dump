/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "rpg.h"

int create_all_sprite(window *win)
{
    if (create_animation_player(win) == 84)
        return 84;
    if (create_animation_bandit(win) == 84)
        return 84;
    if (create_animation_boss(win) == 84)
        return 84;
    if (create_animation_women(win) == 84)
        return 84;
    if (create_animation_forestboy(win) == 84)
        return 84;
    if (create_animation_grandpa(win) == 84)
        return 84;
    if (create_circle_parchment(win) == 84)
        return 84;
    if (create_circle_chest(win) == 84)
        return 84;
    return 0;
}
