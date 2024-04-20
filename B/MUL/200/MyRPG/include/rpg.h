/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg.h
*/

#include <stdbool.h>
#include "inventory.h"
#include "struct.h"
#include "caracters.h"
#include "gameplay.h"
#include "utils.h"

#ifndef RPG
    #define RPG

    #define name "SUPREMACY"

    //SRC
        //WINDOW
            //create.c
            sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y,
            unsigned int bpp, int type);
            int create_window(window *win);

            //manage.c
            int manage_window(window *win);

        //create.c
        int create_all(window *win, map_t **map);

        //malloc.c
        int malloc_all(window *win);

        //update.c
        int update_all(window *win, map_t *map);

#endif
