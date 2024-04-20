/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw.c
*/

#include "./include/my.h"

int check_dir(struct plane *plane, int index, sfVector2f pos, int state)
{
    if (state == 10 && pos.x >= plane[index].end_x &&
    pos.y >= plane[index].end_y) {
        return (plane[index].finish = 1);
    }
    if (state == 20 && pos.x >= plane[index].end_x &&
    pos.y <= plane[index].end_y) {
        return (plane[index].finish = 1);
    }
    if (state == 30 && pos.x <= plane[index].end_x &&
    pos.y >= plane[index].end_y) {
        return (plane[index].finish = 1);
    }
    if (state == 40 && pos.x <= plane[index].end_x &&
    pos.y <= plane[index].end_y) {
        return (plane[index].finish = 1);
    }
    return 0;
}

int state_dir(struct plane *plane, int index)
{
    int state = 0;

    if (plane[index].start_x <= plane[index].end_x &&
    plane[index].start_y <= plane[index].end_y) {
        state = 10;
    }
    if (plane[index].start_x <= plane[index].end_x &&
    plane[index].start_y >= plane[index].end_y) {
        state = 20;
    }
    if (plane[index].start_x >= plane[index].end_x &&
    plane[index].start_y <= plane[index].end_y) {
        state = 30;
    }
    if (plane[index].start_x >= plane[index].end_x &&
    plane[index].start_y >= plane[index].end_y) {
        state = 40;
    }
    return state;
}

int check_finish(struct plane *plane, struct utils *utils)
{
    int index = 0;
    int state = 0;
    int total = 0;

    while (index < utils->total_plane) {
        sfVector2f pos = get_position(plane, index);
        state = state_dir(plane, index);
        check_dir(plane, index, pos, state);
        total = total + plane[index].finish;
        index++;
    }

    if (total == utils->total_plane) {
        return SUCCESS;
    }
    return FAIL;
}
