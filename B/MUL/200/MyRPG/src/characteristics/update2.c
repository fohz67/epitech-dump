/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update2.c
*/

#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

int update_attack(window *win)
{
    char *str = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str = my_itoa(win->characteristics.attack, 10);
    win->characteristics.attack_total = win->characteristics.attack
    + win->characteristics.attack_sword;
    str2 = my_itoa(win->characteristics.attack_total, 10);
    if ((str3 = malloc(sizeof(char) * (my_strlen(str) +
    my_strlen(str2) + 4))) == NULL)
        return 84;
    str3 = my_strcpy(str3, str);
    str3 = my_strcat(str3, " (");
    str3 = my_strcat(str3, str2);
    str3 = my_strcat(str3, ")");
    sfText_setString(win->characteristics.text[1], str3);
    free(str);
    free(str2);
    free(str3);
    return 0;
}
