/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

#include "../../include/my.h"

int count_chars_home(char *path)
{
    int i = 0;
    int slash = 0;

    if (path == NULL)
        exit(84);
    for (; slash != 3; i++) {
        if (path[i] == '/')
            slash++;
        if (path[i] == 0)
            return i;
    }
    return i;
}

char *replace_home(char *path)
{
    char *home = malloc(sizeof(char) * my_strlen(path));
    int chars_home = count_chars_home(path);
    int j = 1;

    if (home == NULL || path == NULL)
        exit(84);
    home[0] = '~';
    if (path[chars_home] != 0) {
        home[1] = '/';
        j++;
        for (int i = chars_home; path[i] != 0; i++, j++)
            home[j] = path[i];
    }
    home[j] = 0;
    return home;
}