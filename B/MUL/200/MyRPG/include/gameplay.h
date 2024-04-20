/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** gameplay.h
*/

#include <stdbool.h>

#ifndef GAMEPLAY
    #define GAMEPLAY

    #define history "Dans un monde fantastique rempli de \
magie\net de mysteres, deux factions ennemies se\n\
faisaient face : les MagicBlades et les Rogues.\nUn jour, les\
Rogues volerent une epee\nlegendaire, tresor national \
transmis de\ngeneration en generation par les MagicBlades.\nLe dernier \
membre du clan est parti recuperer\ncet objet mystique...\n\
\t\t\t\t\t\t\t\t\t\tAppuyez sur Entree..."

    //SRC
        //HEALTH
            //create.c
            int create_health_bar(window *win);

            //update.c
            void display_health_bar(window *win);

        //CHARACTERISTICS
            //create.c
            int create_characteristics(window *win);

            //update.c
            void update_characteristics(window *win);
            int update_stat(window *win);
            int update_xp(window *win);
            int update_attack(window *win);
            int event_key_e(sfEvent *event, window *win);

        //LEVEL
            //update.c
            void update_level(window *win);

            //upgrade_level.c
            int check_xp(window *win);

        //INVENTORY
            //create.c
            int create_inventory(window *win);

            //update.c
            void mouse_click_inventory(window *win);
            int update_inventory(window *win);

            //add_item.c
            int add_item_inventory(window *win, char *item,
            char *desc, char* name_obj);

        //GAMEPLAY
            //create_objects.c
            map_t *create_all_object(map_t *map, window *win);
            map_t *get_node(map_t *map, int index);

            //check_object.c
            int check_type_object(char c);

            //create_collisions.c
            int create_collid(window *win, char **array, int size);
            int create_collid2(window *win, char **array);

            //create.c
            int create_map_and_texture(window *win);

            //open_file.c
            char* open_file(const char *file);

            //update.c
            int display_back(window *win, map_t *map);
            int display_map(window *win, map_t *map);

        //STORY
            //create.c
            int create_story(window *win);

            //update.c
            void update_story(window *win);
            int update_event_story(window *win, sfEvent *event);

        //VIEW PLAYER
            //create.c
            void view_player(window *win);

            //update.c
            void update_view(window *win);
            void reset_view(window *win);

#endif
