/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

int update_xp(window *win)
{
    char * str = NULL;
    char * str2 = NULL;
    char * str3 = NULL;

    str = my_itoa(win->characteristics.exp, 10);
    str2 = my_itoa(win->characteristics.exp_max, 10);
    if ((str3 = malloc(sizeof(char) *
    (my_strlen(str) + my_strlen(str2) + 4))) == NULL)
        return 84;
    str3 = my_strcpy(str3, str);
    str3 = my_strcat(str3, " / ");
    str3 = my_strcat(str3, str2);
    sfText_setString(win->characteristics.text[3], str3);
    free(str);
    free(str2);
    free(str3);
    return 0;
}

static int update_lvl(window *win)
{
    char * str = NULL;
    char * str3 = NULL;

    str = my_itoa(win->characteristics.lvl, 10);
    if ((str3 = malloc(sizeof(char) * my_strlen(str) + 9)) == NULL)
        return 84;
    str3 = my_strcpy(str3, "Level : ");
    str3 = my_strcat(str3, str);
    sfText_setString(win->characteristics.text[4], str3);
    free(str);
    free(str3);
    return 0;
}

int update_stat(window *win)
{
    char* str = NULL;

    str = my_itoa(win->characteristics.health, 10);
    sfText_setString(win->characteristics.text[0], str);
    if (update_attack(win) == 84)
        return 84;
    str = my_itoa(win->characteristics.defense, 10);
    sfText_setString(win->characteristics.text[2], str);
    free(str);
    if (update_xp(win) == 84)
        return 84;
    if (update_lvl(win) == 84)
        return 84;
    return 0;
}

int event_key_e(sfEvent *event, window *win)
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyE
    && (win->state == 2 || win->state == 6)) {
        if (win->state == 2) {
            win->state = 6;
            reset_view(win);
        } else {
            sfView_zoom(win->view, 0.35);
            win->state = 2;
        }
    }
    return 0;
}

void update_characteristics(window *win)
{
    sfRenderWindow_drawSprite(win->window, win->characteristics.back, NULL);
    sfRenderWindow_drawSprite(win->window, win->characteristics.sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(win->window,
        win->characteristics.text[i], NULL);
    }
}
