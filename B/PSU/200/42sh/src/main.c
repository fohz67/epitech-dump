/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "prompt.h"
#include "scripting.h"

char **load_config(void)
{
    char **config = NULL;
    char *rc = NULL;

    if ((rc = read_script(".42shrc")) == NULL) {
        return NULL;
    }
    if ((config = my_tokarray(rc, "\n")) == NULL) {
        free(rc);
        return NULL;
    }
    free(rc);
    return config;
}

void print_prompt(char *theme)
{
    if (theme == NULL) {
        simplist_prompt();
        return;
    }
    if (my_strcmp(theme, "default") == 0)
        default_prompt();
    else
        simplist_prompt();
}

static int loop_main(char **envcp, char **config)
{
    int result = 0;
    int status = 0;
    size_t size = 0;
    char *buffer = NULL;
    char *theme = NULL;

    theme = get_theme(config);
    if ((status = isatty(0)) == 1)
        print_prompt(theme);
    while (getline(&buffer, &size, stdin) != EOF) {
        if (error(buffer, size) != 84)
            result = controller_separators(envcp, config, buffer, result);
        if (status == 1)
            print_prompt(theme);
        free(buffer);
        buffer = NULL;
    }
    free(buffer);
    free(theme);
    return result;
}

int main(int ac, const char **, const char **env)
{
    int result = 0;
    char **envcp = NULL;
    char **config = NULL;

    if (ac != 1)
        return ERROR;
    if ((envcp = copy_env(env)) == NULL)
        return ERROR;
    config = load_config();
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, SIG_IGN);
    result = loop_main(envcp, config);
    free_array(envcp);
    if (config != NULL)
        free_array(config);
    return result;
}
