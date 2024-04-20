/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include "lib.h"
#include "rpg.h"

static int add_sword_end(window *win)
{
    if (win->caracters.boss.death == true) {
        if ((add_item_inventory(win,
        "assets/img/sword_end.png", end_sword, "Magic sword")) == 84)
            return 84;
    }
    return 0;
}

static void equipped_item(window *win, box *tmp)
{
    if (tmp->isHover == true && tmp->text != NULL && tmp->isClicked == true) {
        if (my_strcmp(tmp->name_obj, "basic_sword") == 0) {
            win->characteristics.attack_sword = 3;
            update_stat(win);
        }
        if (my_strcmp(tmp->name_obj, "sparkling sword") == 0) {
            win->characteristics.attack_sword = 10;
            update_stat(win);
        }
        if (my_strcmp(tmp->name_obj, "Magic sword") == 0) {
            win->characteristics.attack_sword = 100;
            update_stat(win);
        }
    }
}

void mouse_click_inventory(window *win)
{
    activate_inventory(win);
    for (box *tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        if (tmp->isHover == true && tmp->text != NULL
        && tmp->isActivate == true) {
            tmp->isClicked = true;
            equipped_item(win, tmp);
        }
    }
}

int update_inventory(window *win)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(win->window);

    sfRenderWindow_drawText(win->window, win->inventory.text, NULL);
    mouse_hover_inventory(win, cursor);
    if (add_sword_end(win) == 84)
        return 84;
    for (box *tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        if (tmp->isHover == true && tmp->text != NULL) {
            sfRenderWindow_drawText(win->window, tmp->text, NULL);
        }
    }
    for (box *tmp = win->inventory.box; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawRectangleShape(win->window, tmp->rect, NULL);
    }
    return 0;
}
