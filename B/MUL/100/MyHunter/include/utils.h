/*
** EPITECH PROJECT, 2022
** utils.h
** File description:
** utils.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#ifndef UTILS_H
    #define UTILS_H

    #define HELP "USAGE\n    ./my_hunter\nDESCRIPTION\n    \
Le My Hunter est un jeu de tir en 2 dimentions.\n    \
Le but est de toucher le plus de dragon possible.\n    \
Plus tu touche de dragons, plus ils vont vite.. \
Soit prêt tu vas cringer bb\n"
    #define LABEL_NAME "MY HUNTER"
    #define LABEL_SCORE "SCORE"
    #define BACKGROUND "./src/background.png"
    #define SPRITESHEET "./src/spritesheet.png"
    #define CURSOR "./src/shot.png"
    #define HEART "./src/heart.png"
    #define START "./src/start.png"
    #define START_HOVER "./src/start_hover.png"
    #define MAPS "./src/maps.png"
    #define RAW "./src/frame.png"
    #define FONT "./src/font.ttf"
    #define MUSIC "./src/music.ogg"
    #define GUN "./src/gun.ogg"

struct sprite {
    sfSprite *sp_bg;
    sfSprite *sp_duck;
    sfSprite *sp_shot;
    sfSprite *sp_h1;
    sfSprite *sp_h2;
    sfSprite *sp_h3;
    sfSprite *sp_start;
};

struct vector {
    sfVector2f vector;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfVector2f posDead;
};

struct game {
    int min_duck_x;
    int min_duck_y;
    int max_duck_x;
    int max_duck_y;
    int life;
    int score;
    int state;
    int music;
    sfText* text;
    sfText* text_score;
    sfFont* font;
};

struct utils {
    sfEvent event;
    sfRenderWindow *window;
    sfClock *clock;
    sfIntRect rect;
    sfMusic *music;
    sfMusic *gun;
};

struct texture {
    sfTexture *background;
    sfTexture *spritesheet;
    sfTexture *mouse;
    sfTexture *heart;
    sfTexture *start;
    sfTexture *starthov;
};

#endif
