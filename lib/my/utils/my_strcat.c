/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** desc
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest , char *src)
{
    if (dest == NULL || src == NULL) {
        return (NULL);
    }
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    if (str == NULL)
        exit(84);
    int i;

    for (i = 0; i != my_strlen(dest); i++) {
        str[i] = dest[i];
    }
    for (int a = 0; a != my_strlen(src); a++, i++) {
        str[i] = src[a];
    }
    str[i] = '\0';
    return (str);
}