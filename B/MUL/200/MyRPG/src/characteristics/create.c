/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

static const char quest[] = "Quete: retrouver l'epee";

static void position(window *win)
{
    sfText_setPosition(win->characteristics.text[0], (sfVector2f){330, 230});
    sfText_setPosition(win->characteristics.text[1], (sfVector2f){330, 420});
    sfText_setPosition(win->characteristics.text[2], (sfVector2f){330, 610});
    sfText_setPosition(win->characteristics.text[3], (sfVector2f){330, 800});
}

static void set_background_inventory(window *win)
{
    sfSprite_setTexture(win->characteristics.sprite,
    win->characteristics.texture, sfTrue);
    sfSprite_setTexture(win->characteristics.back,
    win->characteristics.text_back, sfTrue);
    sfSprite_setPosition(win->characteristics.back, (sfVector2f){0, 0});
    sfSprite_setPosition(win->characteristics.sprite, (sfVector2f){100, 100});
}

static int init_caracteristics(window *win)
{
    if ((win->characteristics.sprite = sfSprite_create()) == NULL)
        return 84;
    if ((win->characteristics.texture = sfTexture_createFromFile
    ("assets/img/characteristics_player.png", NULL)) == NULL)
        return 84;
    if ((win->characteristics.back = sfSprite_create()) == NULL)
        return 84;
    if ((win->characteristics.text_back = sfTexture_createFromFile
    ("assets/img/back_inventory.jpg", NULL)) == NULL)
        return 84;
    win->characteristics.health = 30;
    win->characteristics.attack = 10;
    win->characteristics.attack_sword = 0;
    win->characteristics.attack_total = 0;
    win->characteristics.defense = 10;
    win->characteristics.exp = 0;
    win->characteristics.exp_max = 5;
    win->characteristics.lvl = 1;
    set_background_inventory(win);
    return 0;
}

static void create_quest(window *win)
{
    sfText_setFont(win->characteristics.text[4], win->font);
    sfText_setCharacterSize(win->characteristics.text[4], 130);
    sfText_setScale(win->characteristics.text[4], (sfVector2f){0.1, 0.1});
    sfText_setColor(win->characteristics.text[4], sfWhite);
    sfText_setOutlineColor(win->characteristics.text[4], sfBlack);
    sfText_setOutlineThickness(win->characteristics.text[4], 10);

    sfText_setFont(win->characteristics.text[5], win->font);
    sfText_setCharacterSize(win->characteristics.text[5], 260);
    sfText_setScale(win->characteristics.text[5], (sfVector2f){0.07, 0.07});
    sfText_setColor(win->characteristics.text[5], sfWhite);
    sfText_setOutlineColor(win->characteristics.text[5], sfBlack);
    sfText_setOutlineThickness(win->characteristics.text[5], 20);
    sfText_setString(win->characteristics.text[5], quest);
}

int create_characteristics(window *win)
{
    if (init_caracteristics(win) == 84)
        return 84;
    for (int i = 0; i < 4; i++) {
        if ((win->characteristics.text[i] = sfText_create()) == NULL) {
            return 84;
        }
        sfText_setFont(win->characteristics.text[i], win->font);
        sfText_setCharacterSize(win->characteristics.text[i], 70);
        sfText_setColor(win->characteristics.text[i], sfWhite);
    }
    if ((win->characteristics.text[4] = sfText_create()) == NULL)
        return 84;
    if ((win->characteristics.text[5] = sfText_create()) == NULL)
        return 84;
    create_quest(win);
    if (update_stat(win) == 84)
        return 84;
    position(win);
    return 0;
}
