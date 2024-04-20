/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** MyH
*/

#ifndef MY_H
    #define MY_H

int my_put_char(char);
int my_put_int(int);
int my_put_unsigned(unsigned int nb);
int my_put_string(const char *);
int my_put_nbase(unsigned int nb, const char *, int, int);
int my_put_g(double, const char *, int, char);
int my_put_f(double, const char *, int, char);
int my_put_e(double, const char *, int, char);
int my_put_zero(int, int);
int my_put_space(const char *, int, int);
int my_get_int(const char *);
int my_get_digit(const char *, int, char);
int my_get_alpha(char);
int my_get_num(char);
long long int my_get_power(int);
int my_get_int_len(int);
int my_get_zero(double);
int my_get_double_len(int, int);
int display_basic(double, int);
int display_scientific_z(double, int, char c);
int display_scientific(double, int, char c);
int display_superior(double, int, char);
int my_printf(const char *, ...);
int my_put_string_format(const char *, const char *, int);
int my_get_string_len(const char *);
int my_put_int_format(int, const char *, int);
int my_put_u_format(unsigned int nb, const char *, int);
int my_get_unsigned_len(unsigned int nb);

#endif
