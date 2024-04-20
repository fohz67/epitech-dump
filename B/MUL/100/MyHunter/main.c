/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

static sfRenderWindow *sfcreate_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, title, sfClose, NULL));
}

void sfdestroytexture(struct texture *t)
{
    sfTexture_destroy(t->background);
    sfTexture_destroy(t->spritesheet);
    sfTexture_destroy(t->mouse);
    sfTexture_destroy(t->heart);
    sfTexture_destroy(t->start);
    sfTexture_destroy(t->starthov);
}

void sfdestroy(struct sprite *s, struct utils *u, struct game *g)
{
    sfMusic_destroy(u->music);
    sfMusic_destroy(u->gun);
    sfSprite_destroy(s->sp_bg);
    sfSprite_destroy(s->sp_duck);
    sfSprite_destroy(s->sp_shot);
    sfSprite_destroy(s->sp_h1);
    sfSprite_destroy(s->sp_h2);
    sfSprite_destroy(s->sp_h3);
    sfSprite_destroy(s->sp_start);
    sfClock_destroy(u->clock);
    sfFont_destroy(g->font);
    sfText_destroy(g->text);
    sfRenderWindow_destroy(u->window);
}

int sfgame_start(struct sprite *s, struct utils *u,
struct game *g, struct vector *v)
{
    struct texture t = {sfTexture_createFromFile(BACKGROUND, NULL),
    sfTexture_createFromFile(SPRITESHEET, NULL),
    sfTexture_createFromFile(CURSOR, NULL),
    sfTexture_createFromFile(HEART, NULL),
    sfTexture_createFromFile(START, NULL),
    sfTexture_createFromFile(START_HOVER, NULL)};
    if (sfset_sprites(s, u, &t) == 84) return 84;
    while (sfRenderWindow_isOpen(u->window)) {
        sfRenderWindow_display(u->window);
        sfRenderWindow_clear(u->window, sfBlack);
        while (sfRenderWindow_pollEvent(u->window, &u->event))
            sfmanage(s, u, g, v);
        if (g->state == 1)
            sfduck_animation(s, u, g, v);
        sfmusic(u, g);
        sfanimation(s, u, g, &t);
        sfdraw_sprites(s, u, g, v);
    }
    sfdestroytexture(&t);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, HELP, 221);
        return 0;
    }
    sfMusic *music = sfMusic_createFromFile(MUSIC);
    sfMusic *gun = sfMusic_createFromFile(GUN);
    sfFont *font = sfFont_createFromFile("./src/font.ttf");
    if (!music || !gun || !font) return 84;
    struct sprite s = {sfSprite_create(), sfSprite_create(),
    sfSprite_create(), sfSprite_create(), sfSprite_create(),
    sfSprite_create(), sfSprite_create()};
    struct vector v = {{1, 0}, {980, 20}, {900, 20}, {820, 20}, {-100, -100}};
    struct game g = {0, 0, 0, 0, 3, 0, 0, 0, sfText_create(),
    sfText_create(), font};
    struct utils u = {{0}, sfcreate_window(1080, 720, 32, LABEL_NAME),
    sfClock_create(), {0, 0, 110, 110}, music, gun};
    if (sfgame_start(&s, &u, &g, &v) == 84) return 84;
    sfdestroy(&s, &u, &g);
    return 0;
}
