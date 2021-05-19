/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** desc
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *str_to_cpy)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(str_to_cpy) + 1));

    if (str == NULL)
        return NULL;
    for (; str_to_cpy[i] != 0; i++)
        str[i] = str_to_cpy[i];
    str[i] = 0;
    return str;
}
