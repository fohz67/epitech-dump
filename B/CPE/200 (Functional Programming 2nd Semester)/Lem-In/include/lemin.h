/*
** EPITECH PROJECT, 2022
** lemin.h
** File description:
** lemin.h
*/

#include <stdbool.h>

#ifndef LEMIN_H
    #define LEMIN_H

    #define LABEL "lem_in"

    typedef struct stack_t {
        struct list_t* room;
        struct stack_t* next;
    } stack_t;
    typedef struct list_t {
        int name;
        int dist;
        struct link_t* ptr_link;
        struct list_t* next;
    } list_t;

    typedef struct link_t {
        struct list_t* link_room;
        struct link_t* next;
    } link_t;

    typedef struct anthill {
        int nb_ant;
        int nb_rooms;
        int start_room;
        int end_room;
        int **tunnels;
        int data_index;
        int tunnel_index;
        int start_index;
        int end_index;
    } anthill;

    float my_abs(float nb);
    void my_free_array(char **array);
    void my_free_intarray(int **array);
    float my_getfloat(const char *str);
    int my_getnbr(const char *str);
    int my_getsize_array(char **array);
    bool my_isnbr(char *str);
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
    int my_putstr_parser(const char *str);
    int my_puterror(const char *str);
    int my_skipsep(const char *str, int i);
    char **my_str_to_word_array(char const *str);
    char *my_strcat(char *dest, const char *src);
    int my_strcmp(const char *s1, const char *s2);
    int my_strncmp(const char *s1, const char *s2, int n);
    char *my_strcpy(char *dest, const char *src);
    char *my_strncpy(char* dest, const char *src, int n);
    char *my_stricpy(char* dest, const char *src, int n);
    char *my_strdup(const  char *src);
    char *my_strndup(const  char *src, int n);
    char* my_stridup(const char* src, int n);
    int my_strlen(const char *str);
    char *my_strtok(char *str, const char *delim);
    void my_swap(char *strA, char *strB);
    char **my_tokarray(char *buffer, char *separators);
    char *my_word_array_to_str(char **array);

    //Src folder
    int structure(anthill *ant);

        //Parser folder
            //ant.c
            int get_ants(char *line, anthill *ant);

            //data.c
            int read_data(char *line, anthill *ant);

            //parsing.c
            int parse_data(anthill *ant);

            //room.c
            int get_room(char *line);

            //tunnel.c
            int get_tunnel(char *line, anthill *ant, bool status);

        //PATH_FINDING folder
            //chained_list_room.c
            list_t* create_graph(list_t *graph, anthill *ant);

            //chained_list_link.c
            list_t *create_link(anthill *ant, list_t *graph);
            list_t *get_node(list_t *graph, int index);
            void print_graph(list_t *graph);

            //free_chained_list.c
            void free_graph(list_t *graph);

            //set_dist.c
            list_t *set_dist(list_t *graph, anthill *ant);
            void print_dist(list_t *graph);

            //algo.c
            void print_moves(list_t *graph, anthill *ant);
#endif
