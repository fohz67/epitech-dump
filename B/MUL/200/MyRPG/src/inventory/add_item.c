/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add_item.c
*/

#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

static int already_in_inventory(window *win, char *name_object)
{
    box *tmp = NULL;
    int quantity = 0;

    for (tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        if (tmp->name_obj != NULL &&
        my_strcmp(tmp->name_obj, name_object) == 0) {
            quantity += 1;
            return 1;
        }
    }
    return 0;
}

static int inventory_condition(window *win, box *tmp, char *item, char *desc)
{
    if ((tmp->texture = sfTexture_createFromFile(item, NULL)) == NULL)
        return 84;
    sfRectangleShape_setFillColor(tmp->rect, sfWhite);
    sfRectangleShape_setTexture(tmp->rect, tmp->texture, sfTrue);
    if ((tmp->text = sfText_create()) == NULL)
        return 84;
    sfText_setFont(tmp->text, win->font);
    sfText_setCharacterSize(tmp->text, 40);
    sfText_setString(tmp->text, desc);
    sfText_setColor(tmp->text, sfBlack);
    sfText_setOutlineColor(tmp->text, sfWhite);
    sfText_setOutlineThickness(tmp->text, 2);
    sfText_setPosition(tmp->text, (sfVector2f){800, 700});
    return 1;
}

int add_item_inventory(window *win, char *item, char *desc, char* name_obj)
{
    box *tmp = NULL;
    int status = 0;

    for (tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        if (tmp->texture == NULL && already_in_inventory(win, name_obj) == 0) {
            tmp->name_obj = name_obj;
            status = inventory_condition(win, tmp, item, desc);
        }
        if (status == 1 || status == 84)
            return status;
    }
    return 0;
}
