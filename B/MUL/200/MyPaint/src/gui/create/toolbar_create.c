/*
** EPITECH PROJECT, 2022
** toolbar_create.c
** File description:
** toolbar_create.c
*/

#include <stdlib.h>
#include "paint.h"

static void toolbar_item_create(struct gui *gui, int i,
sfVector2f position, int selector)
{
    int j = 0;
    position.x += 30;
    position.y += 20;

    while (j < number_item(i)) {
        gui->toolbar[i].item[j].text = sfText_create();
        sfText_setString(gui->toolbar[i].item[j].text, name_item(selector));
        sfText_setFont(gui->toolbar[i].item[j].text, gui->font);
        sfText_setCharacterSize(gui->toolbar[i].item[j].text, SIZE_FONT_ITEM);
        sfText_setFillColor(gui->toolbar[i].item[j].text, sfWhite);
        sfText_setPosition(gui->toolbar[i].item[j].text, position);
        position.y += 40;
        selector++;
        j++;
    }
}

static void toolbar_text_create(struct gui *gui, int i, sfVector2f position)
{
    gui->toolbar[i].text = sfText_create();
    sfText_setString(gui->toolbar[i].text, name_toolbar(i));
    sfText_setFont(gui->toolbar[i].text, gui->font);
    sfText_setCharacterSize(gui->toolbar[i].text, SIZE_FONT_TOOLBAR);
    sfText_setPosition(gui->toolbar[i].text, position);
}

static void toolbar_rect_create(struct gui *gui, int i, sfVector2f position)
{
    sfVector2f size_item = {200, 20 + number_item(i) * 40 + 15};
    sfColor color_item = {147, 148, 174, 255};

    gui->toolbar[i].rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(gui->toolbar[i].rect, position);
    sfRectangleShape_setFillColor(gui->toolbar[i].rect, color_item);
    sfRectangleShape_setSize(gui->toolbar[i].rect, size_item);
}

void toolbar_create(struct gui *gui)
{
    int i = 0;
    int selector = 0;
    sfVector2f position = {50, 30};
    sfVector2f pos_item = {50, 90};

    while (i < TOOLBAR) {
        gui->toolbar[i].item = malloc(sizeof(struct toolbar_item_st) *
        number_item(i));
        toolbar_rect_create(gui, i, pos_item);
        toolbar_text_create(gui, i, position);
        toolbar_item_create(gui, i, pos_item, selector);
        position.x += sfText_getLocalBounds(gui->toolbar[i].text).width + 35;
        pos_item.x += sfText_getLocalBounds(gui->toolbar[i].text).width + 35;
        selector += number_item(i);
        i++;
    }
}
