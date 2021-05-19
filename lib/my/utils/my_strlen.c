/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** desc
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != 0)
        i++;
    return i;
}
