/*
** EPITECH PROJECT, 2023
** prompt.c
** File description:
** prompt.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "scripting.h"

static char *get_pwd(void)
{
    char *pwd = NULL;

    pwd = getcwd(NULL, 0);
    if (pwd == NULL)
        return NULL;
    return pwd;
}

static char *get_branch(void)
{
    FILE *fp = NULL;
    char *branch = NULL;

    if ((fp = popen("git branch | grep \\* | cut -d ' ' -f2", "r")) == NULL)
        return NULL;
    if ((branch = malloc(sizeof(char) * 1024)) == NULL)
        return NULL;
    if (fgets(branch, 1024, fp) == NULL)
        return NULL;
    if (pclose(fp) == -1)
        return NULL;
    for (int i = 0; branch[i] != '\0'; i++)
        if (branch[i] == '\n')
            branch[i] = '\0';
    return branch;
}

void default_prompt(void)
{
    char *branch = NULL, *pwd = NULL;

    if ((pwd = get_pwd()) == NULL) {
        my_putstr("$> ");
        return;
    }
    if (get_if_repo()) {
        if ((branch = get_branch()) == NULL) return;
        my_putstr("\033[1;32m┌[\033[1;37m");
        my_putstr(pwd);
        my_putstr("\033[1;32m]-[\033[1;37mgit://");
        my_putstr(branch);
        my_putstr("\033[0;32m ✓\033[1;32m]\n└>\033[0m ");
        free(branch);
    } else {
        my_putstr("\033[1;32m┌[\033[1;37m");
        my_putstr(pwd);
        my_putstr("\033[1;32m]\n└>\033[0m ");
    }
    free(pwd);
}

static void print_simplist_prompt(char **current_cwd)
{
    char *branch = NULL;

    if (get_if_repo()) {
        branch = get_branch();
        if (branch == NULL)
            return;
        my_putstr("\033[1;32m➜  \033[1;37m");
        my_putstr(current_cwd[my_getsize_lines_array(current_cwd) - 1]);
        my_putstr(" \033[1;32m[\033[1;37mgit://");
        my_putstr(branch);
        my_putstr("\033[0;32m ✓\033[1;32m]\033[0m ");
        free(branch);
    } else {
        my_putstr("\033[1;32m➜  \033[1;37m");
        my_putstr(current_cwd[my_getsize_lines_array(current_cwd) - 1]);
        my_putstr("\033[0m ");
    }
}

void simplist_prompt(void)
{
    char *pwd = NULL;
    char **current_cwd = NULL;

    if ((pwd = get_pwd()) == NULL ||
    (current_cwd = my_tokarray(pwd, "/")) == NULL) {
        my_putstr("$> ");
        return;
    }
    print_simplist_prompt(current_cwd);
    free(pwd);
    free_array(current_cwd);
}
