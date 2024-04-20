/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#include <stdbool.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

    #define SUCCESS 0
    #define FAILURE 1
    #define ERROR 84

    //LIBRARY
    float my_abs(float nb);
    void free_array(char **array);
    float my_getfloat(const char *str);
    int my_getnbr(const char *str);
    int my_getsize_array(char **array);
    int my_getsize_lines_array(char **array);
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
    char* my_strtok(char* str, const char* delim);
    int my_strlen(const char *str);
    void my_swap(char *strA, char *strB);
    char **my_tokarray(char *buffer, char *separators);
    char **my_tokarray_duo(char *buffer, char *separators);
    char *my_word_array_to_str(char **array);
    void sigint_handler(int sig);
    int controller_or_separators(char **envcp, char **config, char *buffer,
    int result);

    //Src folder
        //booleans.c
        bool is_last_command(char **cmd, char *path);
        bool is_bin(char *filename);
        bool is_directory(char **cmd, char *path);
        bool is_only_digit(char *str);
        bool is_artificial_cmd(char *cmd);
        bool is_alphanumeric(const char c);
        bool is_alpha(const char c);
        int get_if_repo(void);

        //engine.c
        void engine_main(char **envcp, char **config, char *buffer, int *fd);

        //error.c
        int error(char *buffer, size_t size);

        //segfault.c
        int segfault(int status);

        //Controllers

            //and_separators.c
            int controller_and_separators(char **envcp, char **config,
            char *buffer, int result);

            //pipes.c
            int controller_pipe(char **envcp, char **config, char *buffer,
            int result);

            //redirections.c

            int controller_redirection(char **envcp, char **config,
            char *buffer, int *fd);
            int controller_input_redirect(char **envcp, char **config,
            char *buffer, int *fd);
            void double_redirect_par(char* filename);


            //separators.c
            int controller_separators(char **envcp, char **config,
            char *buffer, int result);

        //Environment subfolder
            //environment.c
            char **copy_env(const char **envp);
            char *retrieve_data_env(char **envcp, char *name, int n);

            //paths.c
            char *verify_paths(char **cmd, char **envcp);

        //Command subfolder
            //artificial.c
            int execute_artificial(char **cmd, char **envcp, char *buffer,
            int *fd);
            void exec_pipe_builtin(char **cmd, char **envcp, char *buffer,
            int *fd);

            //real.c
            void execute_command(char **cmd, char **envcp, char *path,
            int *fd);
            void execute_real(char **cmd, char **config, char **envcp, int *fd);
            int execute_pipe(int *fd);

            //redirection.c
            int execute_redirection(char **cmd, char **envcp, char *path,
            int *fd);

            //verify.c
            void is_binary(char **cmd, int *fd);
            void is_valid_command(char **cmd, char **envcp, char *path,
            int *fd);

            //All subsubfolder
            int my_cd(char **cmd, char **envcp);
            int my_env(char **envcp);
            int my_exit(char **cmd, char **envcp, char *buffer, int result);
            int my_setenv(char **cmd, char **envcp, char *name, char *value);
            int my_unsetenv(char **cmd, char **envcp);
            int my_echo(char **echo, int result, char **envcp);
            int my_inibitors(int result, char **envcp, char **cmd);


#endif
