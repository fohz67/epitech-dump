/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include "utils.h"
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <sys/stat.h>

//LIBRARY
float my_abs(float nb);
int my_lenword(const char *str, int i);
int my_nbword(const char *str);
int my_nbline(const char *str);
int my_getnbr(const char *str);
int my_getnbr_char(const char str);
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
int my_atoi(char *buffer, int i);
int my_putnbr(int nb);

//==========================ANTMAN==========================

//BUFFER
char *file_content(const char *path, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic);
int file_check(const char *path, char *buffer, int size);
int file_size(const char *path);
char *free_buf(char *buffer);

//DISPATCH
int check_buffer(const char **av, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic);
int put_buffer(const char **av, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic);
int dispatch(const char **av, struct st_dic *st_dic,
struct st_html *st_html, struct st_pic *st_pic);

//INIT DICO
int init_dictionnary(struct st_dic *st_dic);

//INIT HTML
int init_html(struct st_html *st_html);

//INIT PICTURE
int skip_header_picture(struct st_pic *st_pic);
int init_picture(struct st_pic *st_pic);

#endif
