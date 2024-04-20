/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

//LIBRARY
int my_putchar(char c);
int my_putlong(long int nb);
int my_putstr(const char *str);
void my_sort_ascii(int nb, char **tab);
void my_sort_time(int nb, char **tab, const char *path);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int my_strlen(const char *str);

//LS
int basic_ls(int ac, const char **av);
int hard_ls(int ac, const char **av, char *flag);

//UTILS
void define_flags(int ac, const char **av, char *flag);
int display(char **tab, const char *path, char *flag, int size);
void flags(char fchar, char *flag);
void infos(const char *path, char *flag_tab);
void multiflags(const char **av, char *flag, int jindex);
int occurences(int ac, const char **av, char *occurences);
void show(char **tab, const char *path, int size, char *flag);
int tabling(const char *path, char *flag);
long int blksize(char **tab, const char *path, int size);
long int timecheck(char **tab, const char *path, int size);

#endif
