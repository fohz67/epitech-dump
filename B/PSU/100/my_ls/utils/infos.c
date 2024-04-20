/*
** EPITECH PROJECT, 2022
** infos.c
** File description:
** infos.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char types(struct stat sb)
{
    char type;

    if ((sb.st_mode & S_IFMT) == S_IFDIR)
        type = 'd';
    if ((sb.st_mode & S_IFMT) == S_IFLNK)
        type = 'l';
    if ((sb.st_mode & S_IFMT) == S_IFREG)
        type = '-';
    if ((sb.st_mode & S_IFMT) == S_IFBLK)
        type = 'b';
    if ((sb.st_mode & S_IFMT) == S_IFCHR)
        type = 'c';
    if ((sb.st_mode & S_IFMT) == S_IFIFO)
        type = 'p';
    if ((sb.st_mode & S_IFMT) == S_IFSOCK)
        type = 's';

    return type;
}

void permissions(struct stat sb)
{
    my_putchar((sb.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((sb.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((sb.st_mode & S_ISUID) ?
    (sb.st_mode & S_IXUSR ? 's' : 'S') : (sb.st_mode & S_IXUSR ? 'x' : '-'));

    my_putchar((sb.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((sb.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((sb.st_mode & S_ISGID) ?
    (sb.st_mode & S_IXGRP ? 's' : 'S') : (sb.st_mode & S_IXGRP ? 'x' : '-'));

    my_putchar((sb.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((sb.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((sb.st_mode & S_ISVTX) ?
    (sb.st_mode & S_IXOTH ? 't' : 'T') : (sb.st_mode & S_IXOTH ? 'x' : '-'));
}

void date(struct stat sb)
{
    char *date = ctime(&sb.st_mtime);
    int index = 3;
    int dot = 0;

    while (dot < 2 && date[index] != '\0') {
        if (date[index] == 32 && date[index + 1] == 32)
            index = index + 1;
        if (date[index] == ':')
            dot++;
        if (dot < 2)
            my_putchar(date[index]);
        index++;
    }
}

void display_infos(struct stat sb,
                    struct passwd *pwd,
                    struct group *grp,
                    char type)
{
    my_putchar(type);
    permissions(sb);
    my_putstr(". ");
    my_putlong(sb.st_nlink);
    my_putchar(' ');
    my_putstr(pwd->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
    my_putchar(' ');
    if (type == 'c' || type == 'b') {
        my_putlong((long int) sb.st_dev / 256);
        my_putstr(", ");
        my_putlong((long int) sb.st_dev % 256);
    } else {
        my_putlong(sb.st_size);
    }
    date(sb);
    my_putchar(' ');
}

void infos(const char *path, char *flag_tab)
{
    struct stat sb;
    stat(path, &sb);

    char type = types(sb);
    struct passwd *pwd;
    struct group *grp;

    pwd = getpwuid(sb.st_uid);
    grp = getgrgid(sb.st_gid);

    if (flag_tab[1] == 'y') {
        display_infos(sb, pwd, grp, type);
    }
}
