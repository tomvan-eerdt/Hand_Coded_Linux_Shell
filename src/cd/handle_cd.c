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

int check_spaces(const char *str)
{
    for (int i = 2; str[i] != 0; i++) {
        if (str[i] != ' ')
            return 0;
    }
    return 1;
}

int count_args(const char *line)
{
    int args = 1;
    for (int i = 0; line[i] != 0; i++) {
        if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1] != 0)
            args++;
    }
    return args;
}

char *extract_path(char *line)
{
    char *str = NULL;
    int y = 0;
    int args = 0;

    for (int i = 2; line[i] != 0; i++) {
        if (line[i] != ' ')
            args++;
    }
    str = malloc(sizeof(char) * args);
    if (str == NULL)
        exit(84);
    for (int i = 2; line[i] != 0; i++) {
        if (line[i] != ' ') {
            str[y] = line[i];
            y++;
        }
    }
    return str;
}

char *change_path(char *line, char *path)
{
    int args = 0;

    if (my_strlen(line) == 5) {
        if (line[3] == '.' && line[4] == '/')
            return NULL;
    }
    if (my_strlen(line) == 4) {
        if (line[3] == '.')
            return NULL;
    }
    args = count_args(line);
    if (args > 2) {
        write(1, "too many arguments\n", 19);
        return NULL;
    }
    return extract_path(line);
}