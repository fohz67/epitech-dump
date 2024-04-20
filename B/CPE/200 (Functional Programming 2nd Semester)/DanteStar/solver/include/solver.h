/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** solver.h
*/

#ifndef SOLVER_H
    #define SOLVER_H

//LIBRARY
float my_abs(float nb);
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
int my_puts(const char *str, int status, int enter);
int my_skipsep(const char *str, int i);
char **my_str_to_word_array(char const *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const  char *src);
int my_strlen(const char *str);
void my_swap(char *strA, char *strB);
char *my_word_array_to_str(char **array);

//BUFFER
char *free_buf(char *buffer);
int file_size(const char *path);
int file_check(const char *path, char *buffer, int size);
char *file_content(const char *path);

//ERROR
int error_condition(char c, int line_len, int count);
int error3(char *buffer);
int error(char *buffer);

//CALCUL
int nb_col(char *buffer);
int nb_line(char *buffer);

//SOLVER
int solver(char **map, char **map_cpy, char *buffer);

//CONVERT_MAZE
void convert_maze(char **maze, char **maze_cpy);

//MV_BASIC
int mv_top(char **maze, int moved, int y, int x);
int mv_left(char **maze, int moved, int y, int x);
int mv_bottom(char **maze, int moved, int y, int x);
int mv_right(char **maze, int moved, int y, int x);

//MV_HARD
int mv_top2(char **maze, int moved, int y, int x);
int mv_left2(char **maze, int moved, int y, int x);
int mv_bottom2(char **maze, int moved, int y, int x);
int mv_right2(char **maze, int moved, int y, int x);

#endif
