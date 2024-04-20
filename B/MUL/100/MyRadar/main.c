/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

static sfRenderWindow *sfcreate_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, title, sfClose, NULL));
}

int verif_env(char **envp)
{
    int index = 0;
    int result = SUCCESS;

    while (envp[index] != NULL) {
        if (my_strcmp(envp[index], "XDG_SESSION_TYPE=tty") == 0) {
            result = ERROR;
        }
        index = index + 1;
    }
    return result;
}

int loop(struct tower *tower, struct plane *plane,
struct utils *utils, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        manage_window(window, utils->event, utils);
        if (check_finish(plane, utils) == SUCCESS) {
            return SUCCESS;
        }
        move_sprites(tower, plane, utils);
        draw_sprites(tower, plane, utils, window);
    }
    return SUCCESS;
}

int main(int ac, const char **av, char **envp)
{
    if (verif_env(envp) == ERROR || envp[0] == NULL)
        return ERROR;
    sfRenderWindow *window = sfcreate_window(1920, 1080, 32, LABEL);
    if (!window)
        return ERROR;
    struct utils utils = {NULL, 0, 0, 0, 0, NULL, NULL, {0}, NULL};
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        write(1, HELP, my_strlen(HELP));
        return SUCCESS;
    }
    if (params_errors(ac, av[1], &utils) == ERROR)
        return ERROR;
    struct tower *tower = malloc(sizeof(struct tower) * utils.total_tower);
    struct plane *plane = malloc(sizeof(struct plane) * utils.total_plane);

    if (struct_matrix(tower, plane, &utils) +
    create_all(tower, plane, &utils) >= ERROR)
        return ERROR;
    loop(tower, plane, &utils, window);
    return destroy_all(tower, plane, &utils, window);
}
