/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** utils.h
*/

#include <stdbool.h>

#ifndef UTILS
    #define UTILS

    #define menu_buttons 4
    #define settings_buttons 6
    #define menu_game_buttons 5

    //SRC
        //MENU
            //create.c
            int create_menu(window *win);

            //update.c
            void update_menu(window *win);

        //MENU_GAME
            //create.c
            int create_menu_game(window *win);

            //update.c
            void update_menu_game(window *win);
            int event_key_escape(sfEvent *event, window *win);

        //MUSIC
            //create.c
            int create_music(window *win);

            //update.c
            void update_music(window *win);

        //SETTINGS
            //create_text.c
            void size_text(window *win);
            void color_text(window *win);
            void attributes_text(window *win);

            //create.c
            int create_settings(window *win);

            //update.c
            void update_settings(window *win);

        //MOUSE
            //activate.c
            void activate_menu(window *win);
            void activate_menu_game(window *win);
            void activate_inventory(window *win);

            //click.c
            void mouse_click(window *win);
            void mouse_click_selector(window *win);

            //compute.c
            void compute_settings(window *win, int i);
            void compute_menu(window *win, int i);
            void compute_menu_game(window *win, int i);

            //hover.c
            void mouse_hover(window *win);
            void mouse_hover_inventory(window *win, sfVector2i cursor);

        //DESTROY
            //destroy.c
            void destroy_all(window *win);
            void destroy_caracters(window *win);
            void destroy_window(window *win);
            void destroy_inv(window *win);

#endif
