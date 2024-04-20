/*
** EPITECH PROJECT, 2022
** utils.h
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H

    #define ERROR 84
    #define SUCCESS 0
    #define BASIC 1
    #define ERROR_FILE -1
    #define NO_VALUE 0
    #define OBSTACLE 'o'
    #define WATER '.'
    #define LAND 'x'
    #define ENDLINE '\n'
    #define ENDSTR '\0'
    #define END "End"

struct square{
    int count;
    int loop;
    int best;
    int best_x;
    int best_y;
    int new;
};

struct generate{
    int index;
    int jndex;
    int kndex;
    int nbmax;
    int nblen;
    int nb;
};

#endif
