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
#include <math.h>

#ifndef UTILS_H
    #define UTILS_H

    #define LABEL "104intersection"
    #define HELP "USAGE\n    \
./104intersection opt xp yp zp xv yv zv p\n\n\
DESCRIPTION\n    \
opt             surface option: 1 for a sphere, 2 for a cylinder, \
3 for a cone\n    \
(xp, yp, zp)    coordinates of a point by which the light ray passes \
through\n    \
(xv, yv, zv)    coordinates of a vector parallel to the light ray\n    \
p               parameter: radius of the sphere, radius of the cylinder, \
or\n                    angle formed by the cone and the Z-axis\n"
    #define HELP_ARG "-h"
    #define SUCCESS 0
    #define FAIL 1
    #define ERROR_FILE -1
    #define ERROR 84
    #define ENDLINE '\n'
    #define TABULATION '\t'
    #define ENDSTR '\0'
    #define END "End"
    #define SPACE 32

struct utils {
    double x;
    double y;
    double z;
    double Vx;
    double Vy;
    double Vz;
    double spec;
};

struct cal {
    double a;
    double b;
    double c;
    double delta;
    double angle;
    double x1;
    double x2;
};

#endif
