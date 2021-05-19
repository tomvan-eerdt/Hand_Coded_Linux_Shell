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

int find_env(v *ev, char *l)
{
    int i = 0;

    for (int y = 0; ev != NULL; y++, ev = ev->next) {
        for (i = 0; l[i] != 0; i++) {
            if (ev->ev[i] != l[i])
                break;
        }
        if (i == my_strlen(l) && ev->ev[i] == '=')
            return (y);
    }
    return (-1);
}

v *reverse_list(v *ev)
{
    v *tmp = ev;
    v *head = NULL;
    v *tmp2 = NULL;

    for (; tmp != NULL ; tmp = tmp->next) {
        tmp2 = create_node(tmp->ev);
        tmp2->next = head;
        head = tmp2;
    }
    return head;
}

v *remove_env(int n, v **ev)
{
    v *tmp = (*ev);
    v *head = NULL;
    v *tmp2 = NULL;

    for (int i = 0; tmp != NULL ; i++, tmp = tmp->next) {
        if (i != n) {
            tmp2 = create_node(tmp->ev);
            tmp2->next = head;
            head = tmp2;
        }
    }
    return reverse_list(head);
}

void remove_multiple_envs(char *l, v **ev, int arg_n)
{
    int n = 0;
    char **args = NULL;

    args = copy_args(arg_n, l);
    for (int a = 1; a != arg_n; a++) {
        n = find_env((*ev), args[a]);
        if (n == -1)
            write(1, "environment variable not found\n", 31);
        else
            (*ev) = remove_env(n, ev);
    }
}

void unsetev(v **ev, char *l, int *command)
{
    int arg_n = 0;

    if (check_str_contains("unsetenv", l) == 0) {
        arg_n = count_args(l);
        if (arg_n == 1) {
            write(1, "Too few arguments\n", 18);
        } else
            remove_multiple_envs(l, ev, arg_n);
        *command = 1;
    }
}