/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str);

int compare_strings(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    for (int i = 0; str1[i] != 0; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}