/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdbool.h>
#include <math.h>

#ifndef MY_H
    #define MY_H

    #define LABEL "nom_du_projet"
    #define HELP "USAGE\n    \
./108trigo fun a0 a1 a2 ...\n\
DESCRIPTION\n    \
fun     function to be applied, among at least “EXP”, \
“COS”, “SIN”, “COSH”\n            \
and “SINH”\n    \
ai      coeficients of the matrix\n"
    #define HELP_ARG "-h"

    struct request {
	    double *content;
	    double *result;
	    int len;
	    int size;
	    int type;
	    int callback;
    };

    enum my_type {
	    EXP,
	    COS,
	    SIN,
	    COSH,
	    SINH
    };

    float my_abs(float nb);
    void my_free(char **array);
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
    void my_swap(char *strA, char *strB);
    char *my_word_array_to_str(char **array);

    //build.c
    struct request *my_build_struct(void);
    struct request *my_build_instance(struct request *req, int ac, char **av);

    //cal.c
    double *my_sub(double *src, double *obj, int len);
    double *my_add(double *src, double *obj, int len);
    double *my_mult(double *src, double *obj, int len, int size);
    double *my_div(double *src, double k, int len, int size);

    //display.c
    void my_display(double *src, int size);

    //error.c
    bool my_valid_params(int ac, char **av);

    //matrix.c
    double *my_basic(int size, int len);
    int my_empty(double *src, int len);
    int my_equal(double *dest, double *src, int len);
    void my_copy(double *dest, double *src, int len);

    //process.c
    int my_process(struct request *req);
    bool my_process_stop(struct request *req, double *current);

    //trigo.c
    void my_exp(struct request *req);
    void my_cos(struct request *req);
    void my_sin(struct request *req);
    void my_acos(struct request *req);
    void my_asin(struct request *req);

    //values.c
    void my_type(struct request *req, char *str);
#endif
