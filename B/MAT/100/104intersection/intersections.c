/*
** EPITECH PROJECT, 2022
** intersections.c
** File description:
** intersections.c
*/

#include "./include/my.h"

void inter_check(struct utils *utils, struct cal *cal)
{
    if (cal->delta < 0) {
        printf("No intersection point.\n");
    }
    if (cal->delta == 0) {
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n",
        utils->x + cal->x1 * utils->Vx,
        utils->y + cal->x1 * utils->Vy,
        utils->z + cal->x1 * utils->Vz);
    }
    if (cal->delta > 0) {
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n(%.3f, %.3f, %.3f)\n",
        utils->x + cal->x1 * utils->Vx,
        utils->y + cal->x1 * utils->Vy,
        utils->z + cal->x1 * utils->Vz,
        utils->x + cal->x2 * utils->Vx,
        utils->y + cal->x2 * utils->Vy,
        utils->z + cal->x2 * utils->Vz);
    }
}

void inter_addcal(struct cal *cal)
{
    cal->delta = cal->b * cal->b - 4 * cal->a * cal->c;
    cal->x1 = ((-cal->b) - sqrt(cal->delta)) / (2 * cal->a);
    cal->x2 = ((-cal->b) + sqrt(cal->delta)) / (2 * cal->a);

    if (cal->delta > 0) {
        if (cal->x1 < cal->x2) {
            double temp = cal->x2;
            cal->x2 = cal->x1;
            cal->x1 = temp;
        }
    }
}

void inter_sphere(struct utils *utils, struct cal *cal)
{
    cal->a =
    pow(utils->Vx, 2) +
    pow(utils->Vy, 2) +
    pow(utils->Vz, 2);

    cal->b =
    (2 * utils->x * utils->Vx) +
    (2 * utils->y * utils->Vy) +
    (2 * utils->z * utils->Vz);

    cal->c =
    pow(utils->x, 2) +
    pow(utils->y, 2) +
    pow(utils->z, 2) -
    pow(utils->spec, 2);

    inter_addcal(cal);
    inter_check(utils, cal);
}

void inter_cylinder(struct utils *utils, struct cal *cal)
{
    cal->a =
    pow(utils->Vx, 2) +
    pow(utils->Vy, 2);

    cal->b =
    (2 * utils->x * utils->Vx) +
    (2 * utils->y * utils->Vy);

    cal->c =
    pow(utils->x, 2) +
    pow(utils->y, 2) -
    pow(utils->spec, 2);

    inter_addcal(cal);
    inter_check(utils, cal);
}

void inter_cone(struct utils *utils, struct cal *cal)
{
    cal->angle = utils->spec * M_PI / 180;

    cal->a =
    pow(utils->Vx, 2) +
    pow(utils->Vy, 2) -
    (pow(utils->Vz, 2) / (tan(cal->angle) * tan(cal->angle)));

    cal->b =
    (2 * utils->x * utils->Vx) +
    (2 * utils->y * utils->Vy) -
    ((2 * utils->z * utils->Vz) / (tan(cal->angle) * tan(cal->angle)));

    cal->c =
    pow(utils->x, 2) +
    pow(utils->y, 2) -
    (pow(utils->z, 2) / (tan(cal->angle) * tan(cal->angle)));

    inter_addcal(cal);
    inter_check(utils, cal);
}
