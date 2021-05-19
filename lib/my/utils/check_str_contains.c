/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** desc
*/

#include <stdio.h>
#include <dirent.h>

int my_strlen(char const *str);

int check_str_contains(char *str, char *str2)
{
    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] != str2[i])
            return (1);
    }
    return (0);
}