/*
** EPITECH PROJECT, 2022
** my_rpg²
** File description:
** create.c
*/

#include "rpg.h"

static const char quest2[] = "Quete: retournez voir le\nvieil homme au village";

void update_level(window *win)
{
    int decal = 0;

    sfRenderWindow_drawText(win->window, win->characteristics.text[4], NULL);
    sfText_setPosition(win->characteristics.text[4], (sfVector2f)
    {win->caracters.player.x - 300, win->caracters.player.y - 160});

    if (win->caracters.grandpa.isQuestActive == true) {
        if (win->caracters.boss.death == true) {
            sfText_setString(win->characteristics.text[5], quest2);
            decal = 30;
        }
        sfRenderWindow_drawText(win->window,
        win->characteristics.text[5], NULL);
        sfText_setPosition(win->characteristics.text[5], (sfVector2f)
        {win->caracters.player.x + 155 - decal, win->caracters.player.y - 175});
    }
}
