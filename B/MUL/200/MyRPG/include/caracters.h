/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** caracters.h
*/

#include <stdbool.h>

#ifndef CARACTERS
    #define CARACTERS

    //SRC
        //ANIM
            //NPC
                //create_npc2.c
                void set_women_rect(window *win);
                void set_forestboy_rect(window *win);
                void set_grandpa_rect(window *win);

                //create_npc.c
                int create_animation_women(window *win);
                int create_animation_forestboy(window *win);
                int create_animation_grandpa(window *win);
                int create_dialog_forestboy(window *win);
                int create_dialog_woman(window *win);

                //update.c
                int update_pnj(window *win);
                void event_key_f(window *win, sfEvent *event);
                int check_zone_grandpa(window *win);
                void check_zone_parchment(window *win);
                int check_zone_chest(window *win);
                void check_zone_woman(window *win);

            //PLAYER
                //create.c
                int create_animation_player(window *win);

                //update_attack.c
                void update_attack_anim_player(window *win);

                //update_collision.c
                void update_collision(window *win);

                //update_player.c
                void update_player(window *win);
                void check_zone_bandit(window *win, int i);
                void check_zone_bandit_view(window *win, int i);
                void check_zone_boss(window *win);
                void check_zone_boss_view(window *win);

                //walk_player.c
                void walk_right_animation(window *win);
                void walk_left_animation(window *win);
                void walk_front_animation(window *win);
                void walk_back_animation(window *win);
                void walk_back_boss_animation(window *win);
                void walk_front_boss_animation(window *win);

            //BANDIT
                //create.c
                int create_animation_boss(window *win);
                int create_animation_bandit(window *win);

                //update.c
                void update_boss(window *win);
                void update_bandit(window *win);
                void pos_bandit(window *win);

                //walk.c
                void walk_right_boss_animation(window *win);
                void walk_left_boss_animation(window *win);
                void walk_right_bandit_animation(window *win, int i);
                void walk_left_bandit_animation(window *win, int i);
                void walk_front_bandit_animation(window *win, int i);
                void walk_back_bandit_animation(window *win, int i);
                void attack_left_bandit(window *win, int i);
                void attack_left_boss(window *win);

            //BOSS
                //update
                int move_boss_diago(window *win);
                int move_boss_diago_two(window *win);
                int move_boss_left_right(window *win);
                int move_boss_frond_back(window *win);
                //create
                int create_dialog_boss(window *win);
            //create.c
            int create_all_sprite(window *win);
            int create_circle_parchment(window *win);
            int create_circle_chest(window *win);

            //update.c
            void update_all_sprite(window *win);
            int move_bandit_diago(window *win, int i);
            int move_bandit_diago_two(window *win, int i);
            int move_bandit_left_right(window *win, int i);
            int move_bandit_frond_back(window *win, int i);

            //update4.c
            int verif_state_grandpa(window *win);

#endif
