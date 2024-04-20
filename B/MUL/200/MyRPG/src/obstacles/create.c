/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

static const char *textures[] = {
    "assets/img/tiles_environment.png",
    "assets/img/tiles_natural.png",
    "assets/img/tiles_single_house.png",
    "assets/img/tiles_tipi.png",
    "assets/img/tiles_ice.png",
    "assets/img/tiles_natural.png",
    "assets/img/castle.png",
    "assets/img/ancient2.png"
};

static int create_map_and_texture2(window *win, char *buffer2)
{
    win->map_texture.map_front = my_tokarray(buffer2, "\n");
    if (create_collid2(win, win->map_texture.map_front) == 84) {
        return 84;
    }
    win->map_texture.texture = malloc(sizeof(sfTexture *) * 8);
    for (int i = 0; i < 8; i++) {
        win->map_texture.texture[i] =
        sfTexture_createFromFile(textures[i], NULL);
        if (win->map_texture.texture[i] == NULL) {
            return 84;
        }
    }
    return 0;
}

int create_map_and_texture(window *win)
{
    char *buffer = NULL;
    char *buffer2 = NULL;
    int size = 0;
    int size2 = 0;

    if ((buffer = open_file("assets/res/map.txt")) == NULL)
        return 84;
    if ((buffer2 = open_file("assets/res/obstacles.txt")) == NULL)
        return 84;
    size = my_strlen(buffer);
    size2 = my_strlen(buffer2);
    win->map_texture.map_back = my_tokarray(buffer, "\n");
    if (create_collid(win, win->map_texture.map_back, size + size2) == 84)
        return 84;
    free(buffer);
    if (create_map_and_texture2(win, buffer2) == 84)
        return 84;
    free(buffer2);
    return 0;
}
