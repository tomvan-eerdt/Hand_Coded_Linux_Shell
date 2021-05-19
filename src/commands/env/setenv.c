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

int check_envs(char **a, int args, v *ve)
{
    v *tmp = ve;

    if (a[1][0] >= 'a' && a[1][0] <= 'z' || a[1][0] >= 'A' && a[1][0] <= 'Z')
        return 0;
    return 1;
}

void create_env(int args_n, v **ve, char *ar)
{
    v *temp = NULL;
    v *lastnode = (*ve);

    for (; lastnode->next != NULL; lastnode = lastnode->next) {}
    temp = create_node(ar);
    lastnode->next = temp;
}

int replace_if_exists(v **ve, char *name, char *value)
{
    v *temp = NULL;
    char *env = NULL;
    v *lastnode = (*ve);

    for (; lastnode != NULL; lastnode = lastnode->next) {
        if (check_str_contains(name, lastnode->ev) == 0) {
            if (lastnode->ev[my_strlen(name)] == '=') {
                env = my_strcpy(name);
                env = my_strcat(env, "=");
                env = my_strcat(env, value);
                lastnode->ev = env;
                return 1;
            }
        }
    }
    return 0;
}

void handle_env(char **ar, int args_n, v **ve)
{
    char *env = NULL;

    if (check_envs(ar, args_n, (*ve)) == 0) {
        if (replace_if_exists(ve, ar[1], ar[2]) == 0) {
            env = my_strcpy(ar[1]);
            env = my_strcat(env, "=");
            env = my_strcat(env, ar[2]);
            create_env(args_n, ve, env);
        }
    }
    else {
        write(1,
        "setenv: Variable name must begin with a letter.\n",
      48);
    }
}

void setev(v **ve, char *l, int *command)
{
    char **ar = NULL;
    int args_n = 0;

    if (check_str_contains("setenv", l) == 0) {
        args_n = count_args(l);
        if (args_n == 3) {
            ar = copy_args(count_args(l), l);
            handle_env(ar, args_n, ve);
        }
        else
            write(1, "Wrong number of arguments\n", 27);
        *command = 1;
    }
}