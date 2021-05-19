/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** desc
*/

#include <stdio.h>
#include <dirent.h>

int get_file_count(char *name)
{
    DIR *dir;
    struct dirent *dp;
    int i = 0;

    dir = opendir(name);
    while ((dp = readdir(dir)) != NULL) {
        i++;
    }
    closedir(dir);
    return (i);
}