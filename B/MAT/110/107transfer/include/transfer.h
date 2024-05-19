/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #define LABEL "107transfer"
    #define HELP "USAGE\n    \
./107transfer [num den]+\n\n\
DESCRIPTION\n    \
num     polynomial numerator defined by its coefficients\n    \
den     polynomial denominator defined by its coefficients\n"
    #define HELP_ARG "-h"

typedef struct coef {
    char **str_a;
    char **str_b;
    int *tab_a;
    int *tab_b;
    double res_a;
    double res_b;
    double res;
    int max_a;
    int max_b;
} transfer;

//LIBRARY
float my_abs(float nb);
float my_getfloat(const char *str);
int my_getnbr(const char *str);
int my_getsize_array(char **array);
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
int my_puts(const char *str, int status, int enter);
int my_skipsep(const char *str, int i);
char **my_str_to_word_array(char const *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const  char *src);
int my_strlen(const char *str);
void my_swap(char *strA, char *strB);
char *my_word_array_to_str(char **array);

void compute(transfer *tr, int ac, const char **av);
void divi(transfer *tr, int ac, const char **av);
transfer *struct1(transfer *tr, const char **av);
transfer *struct2(transfer *tr, const char *arg1, const char *arg2);

#endif
