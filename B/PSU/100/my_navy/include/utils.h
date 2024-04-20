/*
** EPITECH PROJECT, 2022
** utils.h
** File description:
** utils.h
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>

#ifndef UTILS_H
    #define UTILS_H

    #define LABEL "navy"
    #define HELP "USAGE\n     \
./navy [first_player_pid] navy_positions\n\n\
DESCRIPTION\n     \
first_player_pid: only for the 2nd player. pid of the first player.\n     \
navy_positions: file representing the positions of the ships.\n"
    #define HELP_ARG "-h"

typedef struct st_game {
    int other_pid;
    char *buffer;
    char **my_map;
    char **enemy_map;
    int win;
} game;

extern game my_game;

#endif
