/*
** EPITECH PROJECT, 2022
** utils.h
** File description:
** utils.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef UTILS_H
    #define UTILS_H

    #define LABEL "My Radar"
    #define HELP "Air traffic simulation panel\n\nUSAGE\n  \
./my_radar [OPTIONS] path_to_script\n  \
path_to_script    The path to the script file.\n\n\
OPTIONS\n  \
-h                print the usage and quit.\n\n\
USER INTERACTIONS\n  \
‘L’ key           enable/disable hitboxes and areas.\n  \
‘S’ key           enable/disable sprites.\n"
    #define BAD_USAGE "./my_radar: bad argument: \
one file argument is needed\n\
retry with -h to get more informations\n"
    #define NOT_ENOUGH "./my_radar: not enough arguments: \
one file argument is needed\n\
retry with -h to get more informations\n"
    #define TOO_MANY "./my_radar: too many arguments: \
maximum one file argument is needed\n\
retry with -h to get more informations\n"
    #define INVALID "./my_radar: invalid file content /!\\: \
the content of the file is invalid or corrupted\n\
retry with -h to get more informations\n"
    #define BAD_RES "./my_radar: missing resources /!\\: \
please, verify the \"src\" folder\n\
retry with -h to get more informations\n"
    #define SUCCESS 0
    #define FAIL 1
    #define ERROR_FILE -1
    #define ERROR 84
    #define ENDLINE '\n'
    #define TABULATION '\t'
    #define ENDSTR '\0'
    #define END "End"
    #define SPACE 32
    #define TOWER 'T'
    #define PLANE 'A'

struct tower {
    sfSprite *sprite;
    sfTexture *t;
    sfCircleShape *circle;
    float x;
    float y;
    float size;
};

struct plane {
    sfSprite *sprite;
    sfTexture *t;
    sfRectangleShape *rect;
    float start_x;
    float start_y;
    float end_x;
    float end_y;
    float speed;
    float takeoff;
    int finish;
    int safe;
};

struct utils {
    char **tab;
    int total_tower;
    int total_plane;
    int shape_visible;
    int sprite_visible;
    sfSprite *background;
    sfTexture *texture;
    sfEvent event;
    sfClock *clock;
};

#endif
