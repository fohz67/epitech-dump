/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** struct.h
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <stdbool.h>

#ifndef STRUCT
    #define STRUCT

    typedef struct music_t {
        sfMusic** music;
        sfBool isPlaying;
        int vol;
    } music;

    typedef struct button_settings_t {
        sfRectangleShape *button;
        sfRectangleShape *shadow;
        sfVector2f position;
        sfVector2f position_shadow;
        sfVector2f size;
        sfText *text;
        sfBool isHover;
        sfBool isClicked;
        sfBool isReleased;
        sfBool isActivate;
    } button_settings;

    typedef struct slider_settings_t {
        sfRectangleShape *background;
        sfRectangleShape *shadow;
        sfCircleShape *selector;
        sfVector2f position;
        sfVector2f position_shadow;
        sfVector2f position_selector;
        sfVector2f size;
        sfBool isHover;
    } slider_settings;

    typedef struct settings_t {
        sfText **text;
        int state;
        button_settings *button;
        slider_settings slider;
    } settings;

    typedef struct button_t {
        sfRectangleShape *button;
        sfRectangleShape *shadow;
        sfVector2f position;
        sfVector2f position_shadow;
        sfVector2f size;
        sfText *text;
        sfBool isHover;
        sfBool isClicked;
        sfBool isReleased;
        sfBool isActivate;
    } button;

    typedef struct menu_t {
        sfText *text;
        button *button;
    } menu;

    typedef struct button_game_t {
        sfRectangleShape *button;
        sfRectangleShape *shadow;
        sfVector2f position;
        sfVector2f position_shadow;
        sfVector2f size;
        sfText *text;
        sfBool isHover;
        sfBool isClicked;
        sfBool isReleased;
        sfBool isActivate;
    } button_game;

    typedef struct menu_game_t {
        sfText *text;
        button *button;
    } menu_game;

    typedef struct story_t {
        sfTexture *texture;
        sfRectangleShape *rect;
        sfText *text;
        int state;
    } story;

    typedef struct map_texture_t {
        sfTexture **texture;
        char **map_back;
        char **map_front;
    } map_texture;

    typedef struct map_t {
        sfSprite *sprite;
        sfIntRect rect;
        struct map_t *next;
    } map_t;

    typedef struct health_t {
        sfTexture *texture;
        sfSprite *bar;
        sfIntRect rect;
    } health;

    typedef struct collid_t {
        sfRectangleShape *rect;
    } collid;

    typedef struct circle_parchment {
        sfSprite *dialog;
        sfTexture *texture_dialog;
        sfCircleShape *circle;
        sfFloatRect detection;
        sfBool isArround;
    } parchment;

    typedef struct circle_chest {
        sfSprite *dialog_found;
        sfSprite *dialog_empty;
        sfTexture *texture_dialog_found;
        sfTexture *texture_dialog_empty;
        sfCircleShape *circle;
        sfFloatRect detection;
        sfBool isArround;
        sfBool found;
        int count;
    } chest;

    typedef struct woman_t {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        sfVector2f position;
        sfClock *clock;
        sfSprite *dialog;
        sfTexture *texture_dialog;
        sfCircleShape *circle;
        sfFloatRect detection;
        sfBool isArround;
    } woman;

    typedef struct forestboy_t {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        sfVector2f position;
        sfClock *clock;
        sfSprite *dialog;
        sfTexture *texture_dialog;
        sfCircleShape *circle;
        sfFloatRect detection;
        sfBool isArround;
    } forestboy;

    typedef struct grandpa_t {
        sfSprite *sprite;
        sfSprite *dialog;
        sfTexture *texture_dialog;
        sfTexture *texture;
        sfIntRect rect;
        sfVector2f position;
        sfClock *clock;
        sfCircleShape *circle;
        sfFloatRect detection;
        sfBool isArround;
        sfBool isQuestActive;
        sfBool isEnd;
    } grandpa;

    typedef struct boss_t {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect_right;
        sfIntRect rect_left;
        sfIntRect rect_back;
        sfIntRect rect_front;
        sfIntRect rect_att_left;
        sfVector2f position;
        sfBool restart_clock;
        float speed;
        sfClock *clock;
        sfClock *clock_anim;
        sfSprite *dialog;
        sfTexture *texture_dialog;
        sfClock *clock_dialogue;
        sfBool isEnter;
        //SYSTEME ATTACK
        sfCircleShape *circle;
        sfCircleShape *circle_view;
        sfFloatRect detection;
        sfFloatRect detection_view;
        sfClock* clock_attack;
        sfClock* clock_anim_attack;
        sfTime elapsed;
        sfBool isAttacking;
        sfBool isArround;
        sfBool death;
        sfBool check;
        sfBool isArround_view;
        float timeElapsed;
        int attack_frame_count;
        int vie;
        float dx;
        float dy;
        float dy_total;
    } boss;

    typedef struct bandit_t {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect_right;
        sfIntRect rect_left;
        sfIntRect rect_front;
        sfIntRect rect_back;
        sfIntRect rect_att_left;
        sfVector2f position;
        float speed;
        sfClock *clock;
        sfClock *clock_anim;
        sfBool restart_clock;
        sfCircleShape *circle;
        sfFloatRect detection;
        sfBool isAttacking;
        int vie;
        sfBool isArround;
        sfBool isArround_view;
        sfBool death;
        sfBool check;
        sfBool check_death;
        sfCircleShape *circle_view;
        sfFloatRect detection_view;
        sfClock* clock_attack;
        sfClock* clock_anim_attack;
        sfTime elapsed;
        float timeElapsed;
        int attack_frame_count;
        float dx;
        float dy;
        float dy_total;
    } bandit;

    typedef struct player_t {
        sfSprite *sprite;
        sfTexture *texture;
        sfClock* clock;
        sfTime time;
        sfIntRect rect_right;
        sfIntRect rect_left;
        sfIntRect rect_front;
        sfIntRect rect_back;
        sfIntRect rect_att_right;
        sfIntRect rect_att_left;
        sfIntRect rect_att_front;
        sfIntRect rect_att_back;
        sfBool isAttack;
        sfBool d_click;
        sfBool q_click;
        sfBool s_click;
        sfBool z_click;
        int attack_frame_count;
        float x;
        float y;
        float speed;
        int vie;
    } player;

    typedef struct caracters_t {
        player player;
        bandit *bandit;
        grandpa grandpa;
        forestboy forestboy;
        woman woman;
        boss boss;
    } caracters;

    typedef struct box_t {
        char *name_obj;
        sfRectangleShape *rect;
        sfText *text;
        sfTexture *texture;
        sfVector2f position;
        sfBool isHover;
        sfBool isClicked;
        sfBool isActivate;
        struct box_t *next;
    } box;

    typedef struct inventory_t {
        sfText *text;
        box *box;
    } inventory;

    typedef struct characteristics_t {
        sfSprite *sprite;
        sfTexture *texture;
        sfSprite *back;
        sfTexture *text_back;
        sfText **text;
        int health;
        int attack;
        int attack_total;
        int attack_sword;
        int defense;
        int exp;
        int exp_max;
        int lvl;
    } characteristics;

    typedef struct win_t {
        sfRenderWindow *window;
        sfEvent event;
        sfView *view;
        sfSprite *background;
        sfTexture *texture;
        sfVector2f position;
        sfFont *font;
        int state;
        int collid_nb;
        int key;
        menu menu;
        menu_game menu_game;
        map_texture map_texture;
        health health;
        story story;
        settings settings;
        collid *collid;
        music music;
        characteristics characteristics;
        inventory inventory;
        caracters caracters;
        parchment parchment;
        chest chest;
    } window;

#endif
