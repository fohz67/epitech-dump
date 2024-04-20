/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static const char *path[] = {
    "assets/music/song.wav",
    "assets/music/menu.ogg"
};

int create_music(window *win)
{
    win->music.isPlaying = false;
    for (int i = 0; i < 2; i++) {
        win->music.music[i] = sfMusic_createFromFile(path[i]);
        if (win->music.music[i] == NULL) {
            return 84;
        }
        sfMusic_setVolume(win->music.music[i], 50);
        sfMusic_setLoop(win->music.music[i], sfTrue);
    }
    return 0;
}
