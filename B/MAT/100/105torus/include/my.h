/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef MY_H
    #define MY_H


struct st_torus {
    int opt;
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int n;
};

//bisection.c
void display_bisection(struct st_torus *torus, double c, int i);
int bisection(struct st_torus *torus);

//dispatch.c
int dispatch(struct st_torus *torus);

//init.c
void init_structure(const char **av, struct st_torus *torus);

//library.c
int my_isnum(const char *str);
double my_abs(double nb);
double my_calc(struct st_torus *torus, double x);
double my_deriv(struct st_torus *torus, double x);

//newton.c
int newton(struct st_torus *torus);

//rigor.c
int rules(void);
int rigor(int ac, const char **av);

//secant.c
int secant(struct st_torus *torus);
void display_secant(struct st_torus *torus, double c, int i);

#endif
