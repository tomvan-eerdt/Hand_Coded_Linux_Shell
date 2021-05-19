/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** desc
*/

#include <stdio.h>
#include <dirent.h>
#include "../../../include/my.h"
#include <stdlib.h>

v *create_node(char *e)
{
    v *temp = malloc(sizeof(v));
    if (temp == NULL)
        exit(84);
    temp->ev = my_strcpy(e);
    temp->next = NULL;
    return temp;
}