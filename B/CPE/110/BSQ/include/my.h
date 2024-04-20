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
int my_getnbr(const char *str);
int my_nbline(const char *str);
int my_nbcheck(char **tab);

//BSQ
int file_size(char *path);
int file_content(char *path);
int algorithm(char **tab, char *buffer, int size, struct square b);
int algorithm_nobstacle(char **tab, char *buffer, int size);
int show(char **tab, int size, int remove);
int convert(char **tab, int best, int b_x, int b_y);
int square_land(char **tab, int x, int y, int s_y);
int square(char **tab, int x, int y, int count);
int handling(char *buffer, int size, struct square b);
int generate(char **av);

#endif
