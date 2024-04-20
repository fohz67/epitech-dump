/*
** EPITECH PROJECT, 2022
** hangman.h
** File description:
** hangman.h
*/

#ifndef HANGMAN_
    #define HANGMAN_

    char **my_tokarray(char *buffer, char *separators);
    int my_strlen(const char *str);
    void free_array(char **array);
    char *file_content(const char *path);
    int error(int ac, const char *av[], char **array);
    int create_content(int ac, const char *av[]);
    char *choose_word(char **array);
    char read_user(void);
    int hangman(const char *word, int tries);

#endif
