/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

//LIBRARY
float my_abs(float nb);
int my_lenword(const char *str, int i);
int my_nbword(const char *str);
int my_nbline(const char *str);
int my_getnbr(const char *str);
float my_getfloat(const char *str);
int my_isnum(const char *str);
char* my_itoa(int value, int base);
int my_nbrlen(long int nb);
double my_pow(double base, int exponent);
int my_putchar(char c);
int my_putlong(long int nb);
int my_putstr(const char *str);
int my_issep(const char c);
char **my_str_to_word_array(char const *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *strA, const char *strB);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const  char *src);
int my_strlen(const char *str);
void my_swap(char *strA, char *strB);
int my_putnbr(int nb);
int my_skipsep(const char *str, int i);
int my_puts(const char *str, int status, int enter);
int my_strncmp(const char *s1, const char *s2, int n);
void my_putarray(char **array);

//FICHIER
int error_gestion(int ac, const char **av);
int basic_fractals(char *first_pattern, int size);
int fractals_gestion(const char **av);

#endif
