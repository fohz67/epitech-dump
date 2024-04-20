/*
** EPITECH PROJECT, 2023
** scripting.h
** File description:
** scripting.h
*/
#ifndef SCRIPTING_H_
    #define SCRIPTING_H_

char *read_script(char *path);
char *get_theme(char **file);
char **get_alias(char **file, char *cmd);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const *str);
void free_array(char **array);
int tab_len(char **array);
int check_string(char *line);
int check_syntax(char *line);
char **load_config(void);
int check_alias(char *line);

#endif /*SCRIPTING_H_*/
