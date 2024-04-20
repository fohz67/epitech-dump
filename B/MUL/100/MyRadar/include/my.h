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
char **my_str_to_word_antitab_array(char const *str);
int my_getnbr(const char *str);
float my_getfloat(const char *str);
int my_nbline(const char *str);
int my_nbcheck(char **tab);
int my_nbword(const char *str);
float my_abs(float nb);
char* my_itoa(int value, char* buffer, int base);
int my_isnum(const char *str);
double my_pow(double base, int exponent);

//MAIN
int loop(struct tower *tower, struct plane *plane,
struct utils *utils, sfRenderWindow *window);
int errors(int ac, const char *path, struct utils *utils);

//MANAGE
void manage_window(sfRenderWindow *window, sfEvent event, struct utils *utils);
void key_pressed(sfEvent event, struct utils *utils);

//SPRITE
int create_planes(struct plane *plane, struct utils *utils);
int create_towers(struct tower *tower, struct utils *utils);
int create_background(struct utils *utils);
int create_all(struct tower *tower, struct plane *plane,
struct utils *utils);

//BUFFER
int free_buf(char *buffer);
int file_size(const char *path);
int file_validation(char *buffer);
int file_check(const char *path, char *buffer, int size);
int file_content(const char *path, struct utils *utils);

//MATRIX
void matrix_content(char *buffer, struct utils *utils);

//DRAW
void draw_sprites(struct tower *tower, struct plane *plane,
struct utils *utils, sfRenderWindow *window);

//STRUCTS
void struct_tower(struct tower *tower, struct utils *utils, int nb_tower,
int index_bis);
void struct_plane(struct plane *plane, struct utils *utils, int nb_plane,
int index_bis);
int struct_matrix(struct tower *tower, struct plane *plane,
struct utils *utils);

//SHAPE
void shape_circle_tower(struct tower *tower, int index);
void shape_rectangle_shape(struct plane *plane, int index);

//DESTROY
void destroy_background(struct utils *utils, sfRenderWindow *window);
void destroy_plane(struct plane *plane, struct utils *utils);
void destroy_towers(struct tower *tower, struct utils *utils);
int destroy_all(struct tower *tower, struct plane *plane,
struct utils *utils, sfRenderWindow *window);

//MOVE
sfVector2f get_vector(struct plane *plane, int index);
sfVector2f get_position(struct plane *plane, int index);
void move_sprites(struct tower *tower, struct plane *plane,
struct utils *utils);

//CHECK
int check_finish(struct plane *plane, struct utils *utils);
int state_dir(struct plane *plane, int index);
int check_dir(struct plane *plane, int index, sfVector2f pos, int state);

//INTERSECTIONS
void intersections(struct tower *tower, struct plane *plane,
struct utils *utils, int index);
void intersections_plane(struct plane *plane,
struct utils *utils, int index);
void intersections_bis(struct plane *plane, int index, float diff, float sum);

//ERROR
int file_errors(char *buffer);
int params_errors(int ac, const char *path, struct utils *utils);
int struct_matrix_errors(struct utils *utils);
int struct_tower_errors(struct utils *utils, int index_bis);
int struct_plane_errors(struct utils *utils, int index_bis);

#endif
