/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** MyH
*/

#ifndef MY_H_
    #define MY_H_
void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int* , int*);
int my_putstr(char*);
int my_strlen(char*);
int my_getnbr(char*);
void my_sort_int_array(int* , int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char* , char*);
char *my_strncpy(char* , char* , int);
char *my_revstr(char*);
char *my_strstr(char* , char*);
int my_strcmp(char* , char*);
int my_strncmp(char* , char* , int);
char *my_strupcase(char*);
char *my_strlowcase(char*);
char *my_strcapitalize(char*);
int my_str_isalpha(char*);
int my_str_isnum(char*);
int my_str_islower(char*);
int my_str_isupper(char*);
int my_str_isprintable(char*);
int my_showstr(char*);
int my_showmem(char* , int*);
char *my_strcat(char* , char*);
char *my_strncat(char* , char* , int);
char *my_strdup(char*);
char **my_str_to_word_array(char*);
int my_show_word_array(char*);

#endif /*MY_H_*/
