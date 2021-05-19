/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

int check_if_path(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '/')
            return 1;
    }
    return 0;
}