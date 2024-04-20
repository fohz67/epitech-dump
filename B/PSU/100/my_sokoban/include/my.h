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
char* itos(int value, char* buffer, int base);
int my_putchar(char c);
int my_putlong(long int nb);
int my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int my_strlen(const char *str);

//FUNCTIONS
int map(char *buffer, char *buffer2, int size, int line);
int file_content(char *path);

//KEYS.C
int left(char *buffer, char *buffer2, int index);
int upp(char *buffer, char *buffer2, int index, int line);
int right(char *buffer, char *buffer2, int index);
int down(char *buffer, char *buffer2, int index, int line);

//MOVES.C
int check_moves(char *buffer, int line);
int check(char *buffer, char *buffer2);
int occu_checker(char *buffer);
int char_checker(char c);

//GETTERS.C
int pos(char *buffer, int index);
int tap(char *buffer, char *buffer2, int index, int line);
#endif
