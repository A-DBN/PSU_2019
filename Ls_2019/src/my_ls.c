/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "ls.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

void print_line(struct stat *stats, struct dirent *rd_files)
{
    //time_t timestamp = time(NULL);
    //struct tm *date;
    //date = localtime(&date);

    my_putchar(' ');
    my_put_nbr(stats->st_size);
    my_putchar(' ');
    //my_putstr(ctime(&stats->st_ctime));
    //my_put_nbr(date->tm_mday);
    //my_putchar(' ');
    my_putstr(rd_files->d_name);
    my_putchar('\n');
}

void guid(struct stat *stats)
{
    struct passwd *uid;
    struct group *grp;

    uid = getpwuid(stats->st_uid);
    grp = getgrgid(stats->st_gid);
    my_putstr((S_ISDIR(stats->st_mode)) ? "d" : "-");
    my_putstr((stats->st_mode &S_IRUSR) ? "r" : "-");
    my_putstr((stats->st_mode &S_IWUSR) ? "w" : "-");
    my_putstr((stats->st_mode &S_IXUSR) ? "x" : "-");
    my_putstr((stats->st_mode &S_IRGRP) ? "r" : "-");
    my_putstr((stats->st_mode &S_IWGRP) ? "w" : "-");
    my_putstr((stats->st_mode &S_IXGRP) ? "x" : "-");
    my_putstr((stats->st_mode &S_IROTH) ? "r" : "-");
    my_putstr((stats->st_mode &S_IWOTH) ? "w" : "-");
    my_putstr((stats->st_mode &S_IXOTH) ? "x." : "-");
    my_putchar(' ');
    my_put_nbr(stats->st_nlink);
    my_putchar(' ');
    my_putstr(uid->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
}

void ls_l(char **av, int ac)
{
    struct stat stats;
    struct dirent *rd_files;
    DIR *dir_ls;

    if (ac == 2) {
        stat(".", &stats);
        dir_ls = opendir(".");
    } else {
        stat(av[2], &stats);
        dir_ls = opendir(av[2]);
    }
    my_putstr("total ");
    my_put_nbr(stats.st_blocks);
    my_putchar('\n');
    while ((rd_files = readdir(dir_ls)) != 0) {
        if (rd_files->d_name[0] != '.') {
            guid(&stats);
            print_line(&stats,rd_files);
        }
    }
}

int my_ls(int ac, char **av)
{
    struct dirent *read_files;
    DIR *ls_dir;

    if (ac == 1 && (ls_dir = opendir(".")) == NULL)
        return (84);
    if (ac > 1 && (ls_dir = opendir(av[1])) == NULL)
        return (84);
    while ((read_files = readdir(ls_dir)) != 0) {
        if (read_files->d_name[0] != '.') {
            my_putstr(read_files->d_name);
            my_putchar('\n');
        }
    }
    closedir(ls_dir);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (av[1][1] == 'l') {
        ls_l(av, ac);
    }
    if (my_ls(ac ,av) == 84)
        return (84);
    return (0);
}
