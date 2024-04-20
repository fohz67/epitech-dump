/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create2.c
*/

#include "rpg.h"

void set_grandpa_rect(window *win)
{
    win->caracters.grandpa.rect.top = 650;
    win->caracters.grandpa.rect.left = 16;
    win->caracters.grandpa.rect.width = 32;
    win->caracters.grandpa.rect.height = 55;
    win->caracters.grandpa.position.x = 1668;
    win->caracters.grandpa.position.y = 1245;
}

void set_forestboy_rect(window *win)
{
    win->caracters.forestboy.rect.top = 1638;
    win->caracters.forestboy.rect.left = 49;
    win->caracters.forestboy.rect.width = 41;
    win->caracters.forestboy.rect.height = 56;
    win->caracters.forestboy.position.x = 1210;
    win->caracters.forestboy.position.y = 4200;
}

void set_women_rect(window *win)
{
    win->caracters.woman.rect.top = 653;
    win->caracters.woman.rect.left = 18;
    win->caracters.woman.rect.width = 28;
    win->caracters.woman.rect.height = 50;
    win->caracters.woman.position.x = 1540;
    win->caracters.woman.position.y = 1645;
}
