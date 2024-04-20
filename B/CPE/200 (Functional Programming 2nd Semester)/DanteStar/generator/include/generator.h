/*
** EPITECH PROJECT, 2022
** generator.h
** File description:
** generator.h
*/

#ifndef GEN_H
    #define GEN_H

struct maze {
    char **maze;
    char **maze_cpy;
    char *maze_buf;
    int width;
    int height;
};

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

//ERROR
int isnbr(const char *str);
int error(int ac, const char **av);

//CONSTRUCT
int convert_maze(struct maze *mz);
void generate_maze(struct maze *mz);
int allocate_maze(struct maze *mz);

//PERFECT
int perfect(const char **av, int ac);

//IMPERFECT
int imperfect(const char **av, int ac);

//GENERATOR
void generate_paths(struct maze *mz, int x, int y, int z);
void generate_walls(struct maze *mz, int ac);

//FREE
void free_all(struct maze *mz, int result);

#endif
