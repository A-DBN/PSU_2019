/*
** EPITECH PROJECT, 2019
** jvitrac - lib
** File description:
** file_to_str
*/

#include "my.h"
#include <fcntl.h>
//#include <sys/stat.h>

// Warning : this function uses stat. Check for forbidden syscalls.

/*char *file_to_str(char const *path)
{
    struct stat *buf = malloc(sizeof(struct stat));
    char *str;
    int size;
    int fd;
    int i;

    if (stat (path, buf))
        return (NULL);
    size = buf->st_size;
    free (buf);
    fd = open (path, O_RDONLY);
    str = malloc((size + 1) * sizeof(char));
    i = read (fd, str, size);
    str[size] = '\0';
    if (i == -1)
        return (NULL);
    close (fd);
    return (str);
}*/

// Warning : this function uses lseek. Check for forbidden syscalls.

int get_file_size(int fd)
{
    char *s = malloc(2 * sizeof(char));
    int i = 1;

    if (read(fd, s, 1) == -1)
        return (-1);
    while (1) {
        if (read(fd, s, 1) == 0)
            break;
        i++;
    }
    lseek(fd, 0, SEEK_SET);
    free (s);
    return (i);
}

char *file_to_str(char const *path)
{
    char *str = NULL;
    int size;
    int fd;
    int i;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    size = get_file_size(fd);
    str = malloc((size + 1) * sizeof(char));
    i = read(fd, str, size);
    str[size] = '\0';
    if (i == -1)
        return (NULL);
    close(fd);
    return (str);
}