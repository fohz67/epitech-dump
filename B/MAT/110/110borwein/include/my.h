/*
** EPITECH PROJECT, 2022
** lib.h
** File description:
** lib.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#ifndef MY_H
    #define MY_H

    #define LABEL "110borwein"
    #define HELP "USAGE\n    ./110borwein n\n\n\
DESCRIPTION\n    n\tconstant defining the integral to be computed\n"
    #define HELP_ARG "-h"

    float my_abs(float nb);
    void my_free_array(char **array);
    float my_getfloat(const char *str);
    int my_getnbr(const char *str);
    int my_getsize_array(char **array);
    bool my_isnbr(char *str);
    int my_issep(const char c);
    char* my_itoa(int value, int base);
    int my_lenword(const char *str, int i);
    int my_nbline(const char *str);
    int my_nbrlen(long int nb);
    int my_nbword(const char *str);
    double my_pow(double base, int exponent);
    void my_putarray(char **array);
    int my_putchar(char c);
    int my_putlong(long int nb);
    int my_putnbr(int nb);
    int my_putstr(const char *str);
    int my_puterror(const char *str);
    int my_skipsep(const char *str, int i);
    char **my_str_to_word_array(char const *str);
    char *my_strcat(char *dest, const char *src);
    int my_strcmp(const char *s1, const char *s2);
    int my_strncmp(const char *s1, const char *s2, int n);
    char *my_strcpy(char *dest, const char *src);
    char *my_strncpy(char* dest, const char *src, int n);
    char *my_stricpy(char* dest, const char *src, int n);
    char *my_strdup(const  char *src);
    char *my_strndup(const  char *src, int n);
    char* my_stridup(const char* src, int n);
    int my_strlen(const char *str);
    char* my_strtok(char* str, const char* delim);
    void my_swap(char *strA, char *strB);
    char **my_tokarray(char *buffer, char *separators);
    char *my_word_array_to_str(char **array);
    bool is_digit(const char *str);
    double engine(double n, double x);
    void simpson(double n);
    void trapezoidal(double n);
    void midpoint(double n);

#endif
