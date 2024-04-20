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
char* itoa(int value, char* buffer, int base);
int my_putchar(char c);
int my_putlong(long int nb);
int my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int my_strlen(const char *str);
int my_getnbr(const char *str);


//CREATETAB.C
int malloc_int(int ac, struct tabs *my_tabs);
void swipe(int ac, struct tabs *my_tabs);
int create_tab(int ac, const char **av);

//DISPLAY.C
void display_pa(int max, struct tabs *my_tabs);
void display(int i, struct tabs *my_tabs);

//ERROR.C
int error(const char *str);

//MINIMUM.C
int minimum(int ac, struct tabs *my_tabs);

//ORDER.C
int order2(int i, int ac, struct tabs *my_tabs);
int order(int ac, struct tabs *my_tabs);

//SORT.C
int sort_order(int ac, int i, struct tabs *my_tabs);
int *sort_move(int ac, int pos, int flag, struct tabs *my_tabs);
int sort(int ac, struct tabs *my_tabs);

#endif
