/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static const char gp[] = "assets/img/sprite_grandpa.png";
static const char dia_men_to_old[] = "assets/img/2_dialogue_old.png";
static const char dia_men_to_fb[] = "assets/img/2_dialogue_men.png";
static const char dia_men_to_wm[] = "assets/img/woman_dialogue.png";
static const char parchement_texture[] = "assets/img/parchment_text.png";

int create_dialog_forestboy(window *win)
{
    sfVector2f scale = {0.3, 0.3};
    win->caracters.forestboy.dialog = sfSprite_create();
    win->caracters.forestboy.texture_dialog =
    sfTexture_createFromFile(dia_men_to_fb, NULL);
    if (win->caracters.forestboy.texture_dialog == NULL)
        return 84;
    sfSprite_setTexture(win->caracters.forestboy.dialog,
    win->caracters.forestboy.texture_dialog, sfTrue);
    sfSprite_setScale(win->caracters.forestboy.dialog, scale);
    win->caracters.forestboy.circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.forestboy.circle, 50.f);
    sfCircleShape_setFillColor(win->caracters.forestboy.circle,
    sfTransparent);
    return 0;
}

int create_dialog_grandpa(window *win)
{
    sfVector2f scale = {0.3, 0.3};
    win->caracters.grandpa.dialog = sfSprite_create();
    win->caracters.grandpa.texture_dialog =
    sfTexture_createFromFile(dia_men_to_old, NULL);
    if (win->caracters.grandpa.texture_dialog == NULL)
        return 84;
    sfSprite_setTexture(win->caracters.grandpa.dialog,
    win->caracters.grandpa.texture_dialog, sfTrue);
    sfSprite_setScale(win->caracters.grandpa.dialog, scale);
    win->caracters.grandpa.circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.grandpa.circle, 50.f);
    sfCircleShape_setFillColor(win->caracters.grandpa.circle,
    sfTransparent);
    return 0;
}

int create_dialog_woman(window *win)
{
    sfVector2f scale = {0.3, 0.3};
    win->caracters.woman.dialog = sfSprite_create();
    win->caracters.woman.texture_dialog =
    sfTexture_createFromFile(dia_men_to_wm, NULL);
    if (win->caracters.woman.texture_dialog == NULL)
        return 84;
    sfSprite_setTexture(win->caracters.woman.dialog,
    win->caracters.woman.texture_dialog, sfTrue);
    sfSprite_setScale(win->caracters.woman.dialog, scale);
    win->caracters.woman.circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->caracters.woman.circle, 50.f);
    sfCircleShape_setFillColor(win->caracters.woman.circle,
    sfTransparent);
    return 0;
}

int create_circle_parchment(window *win)
{
    sfVector2f scale = {0.5, 0.5};
    win->parchment.dialog = sfSprite_create();
    win->parchment.texture_dialog =
    sfTexture_createFromFile(parchement_texture, NULL);
    if (win->parchment.texture_dialog == NULL)
        return 84;
    sfSprite_setTexture(win->parchment.dialog,
    win->parchment.texture_dialog, sfTrue);
    sfSprite_setScale(win->parchment.dialog, scale);
    win->parchment.circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->parchment.circle, 50.f);
    sfCircleShape_setFillColor(win->parchment.circle,
    sfTransparent);
    return 0;
}

int create_animation_grandpa(window *win)
{
    sfVector2f position = {0, 0};
    sfVector2f scale = {0.6, 0.6};

    set_grandpa_rect(win);
    create_dialog_grandpa(win);
    position = (sfVector2f){win->caracters.grandpa.position.x,
    win->caracters.grandpa.position.y};
    win->caracters.grandpa.texture =
    sfTexture_createFromFile(gp, NULL);
    if (win->caracters.grandpa.texture == NULL)
        return 84;
    win->caracters.grandpa.sprite = sfSprite_create();
    sfSprite_setTexture(win->caracters.grandpa.sprite,
    win->caracters.grandpa.texture, sfTrue);
    sfSprite_setPosition(win->caracters.grandpa.sprite, position);
    sfSprite_setScale(win->caracters.grandpa.sprite, scale);
    sfSprite_setTextureRect(win->caracters.grandpa.sprite,
    win->caracters.grandpa.rect);
    return 0;
}
