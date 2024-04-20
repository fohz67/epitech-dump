/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include "utils.h"

#ifndef MY_H
    #define MY_H

//animation
void sfanimation_button(struct sprite *s, struct game *g,
sfVector2i cursor, struct texture *t);
void sfanimation_cursor(struct sprite *s, struct game *g, sfVector2i cursor);
void sfanimation(struct sprite *s, struct utils *u, struct game *g,
struct texture *t);

//duck
void sfduck_position(struct sprite *s, struct game *g);
void sfduck_animation(struct sprite *s, struct utils *u,
struct game *g, struct vector *v);

//itos
char* itos(int value, char* buffer, int base);

//manage
void sfmanage_click(struct sprite *s, struct game *g,
struct vector *v, sfVector2i cursor);
void sfmanage(struct sprite *s, struct utils *u,
struct game *g, struct vector *v);

//music
void sfmusic(struct utils *u, struct game *g);

//reset
void sfreset_duck(struct sprite *s);
void sfreset_game(struct game *g, struct vector *v);

//score
void sfscore(struct utils *u, struct game *g);

//sprite
void sfdraw_heart(struct sprite *s, struct utils *u,
struct game *g, struct vector *v);
void sfdraw_sprites(struct sprite *s, struct utils *u,
struct game *g, struct vector *v);
int sfset_sprites(struct sprite *s, struct utils *u, struct texture *t);

//state
void sfdraw_menu(struct sprite *s, struct utils *u, struct game *g);
void sfdraw_game(struct sprite *s, struct utils *u,
struct game *g, struct vector *v);
void sfdraw_endgame2(struct utils *u, struct game *g);
void sfdraw_endgame(struct sprite *s, struct utils *u, struct game *g);

#endif
