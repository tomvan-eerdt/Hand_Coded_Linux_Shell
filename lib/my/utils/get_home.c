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

char *copy_part_str(char *str, int a);

int check_str_contains(char *str, char *str2);

char *get_home_dir(char **ev)
{
    for (int i = 0; ev[i] != NULL; i++) {
        if (check_str_contains("HOME", ev[i]) == 0 && ev[i][4] == '=') {
            return copy_part_str(ev[i], 5);
        }
    }
    return NULL;
}