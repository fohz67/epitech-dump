/*
** EPITECH PROJECT, 2022
** utils.h
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H

    #define LABEL "antman"
    #define HELP ""
    #define HELP_ARG "-h"

struct st_dic {
    char *buffer;
    int size;
};

struct st_html {
    char *buffer;
    int size;
};

struct st_pic {
    char *buffer;
    char *ascii;
    int size;
};

#endif
