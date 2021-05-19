/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** desc
*/

#include <stdio.h>
#include <dirent.h>

int my_strlen(char const *str);

int compare_part_str(char *str, char *str2, int part)
{
    for (int i = 0; str[i] != '='; i++) {
        if (str[i] != str2[i])
            return (1);
    }
    return (0);
}