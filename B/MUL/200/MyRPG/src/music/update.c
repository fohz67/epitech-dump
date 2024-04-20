/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update.c
*/

#include "rpg.h"

void update_music(window *win)
{
    if (win->music.isPlaying == false) {
        sfMusic_play(win->music.music[0]);
        win->music.isPlaying = true;
    }
}
