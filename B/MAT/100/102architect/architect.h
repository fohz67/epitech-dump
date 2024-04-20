/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#ifndef MY_H
    #define MY_H

    #define HELP "USAGE\n\
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n\n\
DESCRIPTION\n\
    x   abscissa of the original point\n\
    y   ordinate of the original point\n\n    transfo arg1 [arg2]\n\
    -t i j  translation along vector (i, j)\n\
    -z m n  scaling by factors m (x-axis) and n (y-axis)\n\
    -r d    rotation centered in O by a d degree angle\n\
    -s d    reflection over the axis passing through O with an inclination\n\
            angle of d degrees"

#endif
