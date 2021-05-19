/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "../../../include/my.h"
#include "../../../include/myfuncts.h"

int count_envs(char **env)
{
    int y = 0;

    for (; env[y] != NULL; y++) {}
    return y;
}

void env(v *ve, char *l, int *command)
{
    if (compare_strings("env", l) == 0) {
        for (; ve != NULL; ve = ve->next) {
            write(1, ve->ev, my_strlen(ve->ev));
            write(1, "\n", 1);
        }
        *command = 1;
    }
}