/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

#include <stdlib.h>

void my_putchar(char c);

int my_strlen(char const *str);

char *rem_spaces(char *str)
{
    int a = 0;
    int j = 0;
    char *str2 = malloc(sizeof(char) * my_strlen(str));

    if (str[0] != ' ')
        return str;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] != ' ')
            a = 1;
        if (a == 1) {
            str2[j] = str[i];
            j++;
        }
    }
    str2[j] = 0;
    return str2;
}

char *rem_spaces_end(char *str)
{
    int i = my_strlen(str) - 1;

    if (str[i] == ' ') {
        for (; str[i] == ' '; i--) {}
        str[i + 1] = 0;
    }
    i = my_strlen(str);
    if (str[i] == '\t') {
        for (; str[i] == '\t'; i--) {}
        str[i + 1] = 0;
    }
    return str;
}

void rep_tabs(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
}

char *clean_str(char *str)
{
    char *str2 = rem_spaces(str);

    rep_tabs(str2);
    rem_spaces_end(str2);
    return str2;
}