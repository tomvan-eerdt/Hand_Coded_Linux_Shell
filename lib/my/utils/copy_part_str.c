/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** desc
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *copy_part_str(char *str, int a)
{
    char *str2 = NULL;
    int j = 0;

    if (a >= my_strlen(str) || my_strlen(str) < 2)
        return NULL;
    str2 = malloc(sizeof(char) * my_strlen(str));
    if (str2 == NULL)
        exit(84);
    for (int i = a; i != my_strlen(str); i++, j++) {
        str2[j] = str[i];
    }
    str2[j] = 0;
    return str2;
}