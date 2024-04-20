/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include "./utils.h"

#ifndef MY_H
    #define MY_H

//LIBRARY
int my_putchar(char c);
int my_putlong(long int nb);
int my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int my_strlen(const char *str);
int my_nbrlen(long int nb);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_antitab_array(char const *str);
int my_getnbr(const char *str);
float my_getfloat(const char *str);
int my_nbline(const char *str);
int my_nbcheck(char **tab);
int my_nbword(const char *str);
float my_abs(float nb);
char* my_itoa(int value, char* buffer, int base);
int my_isnum(const char *str);

//CHECK
int check_args(int ac, const char **av);

//SHOW
void show_args(const char **av);
void show_type(const char **av, struct utils *utils, struct cal *cal);

//INTERSECTIONS
void inter_check(struct utils *utils, struct cal *cal);
void inter_addcal(struct cal *cal);
void inter_sphere(struct utils *utils, struct cal *cal);
void inter_cylinder(struct utils *utils, struct cal *cal);
void inter_cone(struct utils *utils, struct cal *cal);

//DEFINE
void define_struct(const char **av, struct utils *utils);

#endif
