/*
** EPITECH PROJECT, 2022
** utils.h
** File description:
** utils.h
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef UTILS_H
    #define UTILS_H

    #define HELP "USAGE\n    \
./my_sokoban map\nDESCRIPTION\n    map file representing warehouse map, \
containing '#' for walls, 'P' for the player, 'X' for the boxes and 'O' \
for storage locations.\n"
    #define INVALID_SIZE "Invalid shell's size, please increase it"
    #define ENDLINE '\n'
    #define ENDSTR '\0'
    #define SPACE 32
    #define END "End"
    #define WALL '#'
    #define HOLE 'O'
    #define PLAYER 'P'
    #define CRATE 'X'

#endif
