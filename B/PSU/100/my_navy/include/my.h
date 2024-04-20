/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include "./utils.h"

#ifndef MY_H
    #define MY_H

    #define _GNU_SOURCE

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

//CHECK
int check_errors(int ac);
int check_pos_numbers(void);
int check_pos_letters(void);
int check_pos(void);

//INIT
int init_game(int ac, const char **av, struct sigaction *sig);

//PRINT CONTENT
void edit_map_boat5(void);
void edit_map_boat4(void);
void edit_map_boat3(void);
void edit_map_boat2(void);
void print_map(void);

//CREATE CONTENT
char *free_buf(char *buffer);
int file_check(const char *path, char *buffer, int size);
char *file_content(int ac, const char **av);
char *file_content_map(void);
int file_maps(int ac, const char **av);

//CONNECT
void get_other_pid(int signum, siginfo_t *other_info, void *oldact);
void base_id(struct sigaction *sig);
int first_id(struct sigaction *sig);
int second_id(struct sigaction *sig, const char **av);

//LOOP
int read_attack(void);
void turn2(void);
void turn1(void);
void check_print(int total);
void loop(int turn);

#endif
