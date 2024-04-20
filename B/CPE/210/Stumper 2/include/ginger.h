/*
** EPITECH PROJECT, 2022
** ginger.h
** File description:
** ginger.h of the project
*/

#ifndef GINGER_
    #define GINGER_

    char **load_map(const char *filepath, const char *buf);
    char *file_content(const char *path);
    int manage_errors_map(const char *buffer);
    int manage_errors(int ac, const char **av);
    void engine(const char **av, const char *buffer, char **map);
    void print_map(char **map, int token, int token_max, int mv_left);
    int get_tokens(const char *buffer);
    int get_movements(const char **av);
    void condition_win(int tokens, int max_tokens);
    void get_ginger_pos(char **map, int *ginger_pos);

#endif
