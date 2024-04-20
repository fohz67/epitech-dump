/*
** EPITECH PROJECT, 2023
** create
** File description:
** create
*/

#include "rpg.h"
static const char chest_found[] = "assets/img/chest_found.png";
static const char chest_empty[] = "assets/img/chest_empty.png";
static const char fb[] = "assets/img/sprite_forestboy.png";
static const char wm[] = "assets/img/sprite_woman.png";
static const char end_dialogue[] = "assets/img/boss_dialogue.png";

static int initialise_circle_chest(window *win)
{
    win->chest.count = 0;
    win->chest.dialog_found = sfSprite_create();
    win->chest.texture_dialog_found =
    sfTexture_createFromFile(chest_found, NULL);
    win->chest.dialog_empty = sfSprite_create();
    win->chest.texture_dialog_empty =
    sfTexture_createFromFile(chest_empty, NULL);
    if (win->chest.texture_dialog_found == NULL)
        return 84;
    if (win->chest.texture_dialog_empty == NULL)
        return 84;
    return 0;
}

int create_circle_chest(window *win)
{
    sfVector2f scale = {0.3, 0.3};
    if (initialise_circle_chest(win) == 84)
        return 84;
    sfSprite_setTexture(win->chest.dialog_found,
    win->chest.texture_dialog_found, sfTrue);
    sfSprite_setScale(win->chest.dialog_found, scale);
    sfSprite_setTexture(win->chest.dialog_empty,
    win->chest.texture_dialog_empty, sfTrue);
    sfSprite_setScale(win->chest.dialog_empty, scale);
    win->chest.circle = sfCircleShape_create();
    sfCircleShape_setRadius(win->chest.circle, 30.f);
    sfCircleShape_setFillColor(win->chest.circle,
    sfTransparent);
    return 0;
}

int create_animation_forestboy(window *win)
{
    sfVector2f position = {0, 0};
    sfVector2f scale = {0.6, 0.6};

    set_forestboy_rect(win);
    create_dialog_forestboy(win);
    position = (sfVector2f){win->caracters.forestboy.position.x,
    win->caracters.forestboy.position.y};
    win->caracters.forestboy.texture = sfTexture_createFromFile(fb, NULL);
    if (win->caracters.forestboy.texture == NULL) {
        return 84;
    }
    win->caracters.forestboy.sprite = sfSprite_create();
    sfSprite_setTexture(win->caracters.forestboy.sprite,
    win->caracters.forestboy.texture, sfTrue);
    sfSprite_setPosition(win->caracters.forestboy.sprite, position);
    sfSprite_setScale(win->caracters.forestboy.sprite, scale);
    sfSprite_setTextureRect(win->caracters.forestboy.sprite,
    win->caracters.forestboy.rect);
    return 0;
}

int create_animation_women(window *win)
{
    sfVector2f position = {0, 0};
    sfVector2f scale = {0.6, 0.6};

    set_women_rect(win);
    create_dialog_woman(win);
    position = (sfVector2f){win->caracters.woman.position.x,
    win->caracters.woman.position.y};
    win->caracters.woman.texture = sfTexture_createFromFile(wm, NULL);
    if (win->caracters.woman.texture == NULL) {
        return 84;
    }
    win->caracters.woman.sprite = sfSprite_create();
    sfSprite_setTexture(win->caracters.woman.sprite,
    win->caracters.woman.texture, sfTrue);
    sfSprite_setPosition(win->caracters.woman.sprite, position);
    sfSprite_setScale(win->caracters.woman.sprite, scale);
    sfSprite_setTextureRect(win->caracters.woman.sprite,
    win->caracters.woman.rect);
    return 0;
}

int create_dialog_boss(window *win)
{
    sfVector2f scale = {0.3, 0.3};
    sfVector2f position = {win->caracters.boss.position.x - 120,
    win->caracters.boss.position.y + 200};
    win->caracters.boss.dialog = sfSprite_create();
    win->caracters.boss.texture_dialog =
    sfTexture_createFromFile(end_dialogue, NULL);
    if (win->caracters.boss.texture_dialog == NULL)
        return 84;
    sfSprite_setTexture(win->caracters.boss.dialog,
    win->caracters.boss.texture_dialog, sfTrue);
    sfSprite_setScale(win->caracters.boss.dialog, scale);
    sfSprite_setPosition(win->caracters.boss.dialog, position);
    return 0;
}
