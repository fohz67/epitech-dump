/*
** EPITECH PROJECT, 2022
** lingo.h
** File description:
** file.h of the project
*/

#include <stdbool.h>

#ifndef LINGO_
    #define LINGO_

    char **my_tokarray(char *buffer, char *separators);
    int my_strlen(const char *str);
    void free_array(char **array);
    char *file_content(const char *path);
    int error(char **array);
    int create_content(const char *path);
    char *choose_word(char **array);
    int lingo(const char *word, int len);
    char *read_user(void);
    bool check_win(int round, int len, char *user_word, const char *word);
    char *init_round(int *verif);

#endif
