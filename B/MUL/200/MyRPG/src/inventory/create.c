/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "rpg.h"

static box *add_in_inventory(window *win, box *new_box)
{
    box *tmp = NULL;

    tmp = win->inventory.box;
    if (win->inventory.box == NULL) {
        win->inventory.box = new_box;
        return win->inventory.box;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_box;
    return win->inventory.box;
}

static box *create_box_inventory(window *win, int x, int y)
{
    box *new_box = NULL;

    if ((new_box = malloc(sizeof(box))) == NULL)
        return NULL;
    if ((new_box->rect = sfRectangleShape_create()) == NULL)
        return NULL;
    new_box->text = NULL;
    new_box->texture = NULL;
    new_box->isHover = false;
    new_box->isActivate = false;
    new_box->isClicked = false;
    new_box->name_obj = NULL;
    sfRectangleShape_setPosition(new_box->rect, (sfVector2f){x, y});
    sfRectangleShape_setSize(new_box->rect, (sfVector2f){150, 150});
    sfRectangleShape_setOutlineThickness(new_box->rect, 5);
    sfRectangleShape_setFillColor(new_box->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(new_box->rect, sfBlack);
    new_box->next = NULL;
    win->inventory.box = add_in_inventory(win, new_box);
    return win->inventory.box;
}

static int create_line_inventory(window *win, int y)
{
    int x = 800;

    for (int i = 0; i < 6; i++) {
        create_box_inventory(win, x, y);
        x += 160;
    }
    return 0;
}

int create_inventory(window *win)
{
    int y = 200;

    win->inventory.text = sfText_create();
    sfText_setFont(win->inventory.text, win->font);
    sfText_setCharacterSize(win->inventory.text, 80);
    sfText_setString(win->inventory.text, "Inventaire");
    sfText_setColor(win->inventory.text, sfBlack);
    sfText_setPosition(win->inventory.text, (sfVector2f){1100, 50});
    win->inventory.box = NULL;
    for (int i = 0; i < 3; i++) {
        if ((create_line_inventory(win, y)) == 84)
            return 84;
        y += 160;
    }
    if ((add_item_inventory(win, "assets/img/sword_base.png",
    basic_sword, "basic_sword")) == 84)
        return 84;
    return 0;
}
