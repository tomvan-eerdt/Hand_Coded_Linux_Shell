/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int fs_open_file2(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        return (-1);
    }
    else
        return (fd);
}

char *load_file(char *path)
{
    int fd = fs_open_file2(path);
    if (fd == -1)
        return (NULL);
    struct stat buf;
    stat(path, &buf);
    char *str = malloc(sizeof(char) * (buf.st_size + 1));
    if (str == NULL)
        return (NULL);
    size_t buf_s = buf.st_size;
    int a = read(fd, str, buf_s);

    if (buf.st_size == 0)
        return (NULL);
    str[a] = '\0';
    return (str);
}