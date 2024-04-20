/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdbool.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

    //LIBRARY
    float my_abs(float nb);
    void free_array(char **array);
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
    void my_swap(char *strA, char *strB);
    char **my_tokarray(char *buffer, char *separators);
    char *my_word_array_to_str(char **array);

    //Src folder
        //booleans.c
        bool is_file(char **cmd, char *path);
        bool is_only_digit(char *str);
        bool is_artificial_cmd(char *cmd);
        bool is_alphanumeric(const char c);
        bool is_alpha(const char c);

        //engine.c
        int engine_dispatch(char **envcp, char *buffer, int result);

        //error.c
        int error(char *buffer, size_t size);

        //multicmd.c
        int size_multi_command(char *buffer);

        //segfault.c
        int segfault(int status);

        //Environment subfolder
            //environment.c
            char **copy_env(const char **envp);
            char *retrieve_data_env(char **envcp, char *name, int n);

            //paths.c
            char *verify_paths(char **cmd, char **envcp);

        //Command subfolder
            //artificial.c
            int execute_artificial(char **cmd, char **envcp, char *buffer,
            int result);

            //real.c
            int execute_real(char **cmd, char **envcp);

            //All subsubfolder
            int my_cd(char **cmd, char **envcp);
            int my_env(char **cmd, char **envcp);
            int my_exit(char **cmd, char **envcp, char *buffer, int result);
            int my_setenv(char **cmd, char **envcp, char *name, char *value);
            int my_unsetenv(char **cmd, char **envcp);

#endif
