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
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "../include/my.h"
#include "../include/myfuncts.h"

int count_len_comm(char *line, int a)
{
    int b = 0;
    int s = 0;

    for (int i = 0; line[i] != 0; i++) {
        if (line[i] == ';')
            s++;
        if (s == a)
            b++;
    }
    return b + 1;
}

char **split_commands(sh2 *sh, int seperator)
{
    int s = 0;
    int j = 0;
    char **comm = malloc(sizeof(char *) * (seperator + 2));

    comm[s] = malloc(sizeof(char) * count_len_comm(sh->l, 0));
    for (int i = 0; sh->l[i] != 0; i++, j++) {
        if (sh->l[i] == ';') {
            comm[s][j] = 0;
            s++;
            i++;
            comm[s] = malloc(sizeof(char) * count_len_comm(sh->l, s));
            j = 0;
        }
        comm[s][j] = sh->l[i];
    }
    comm[s][j] = 0;
    comm[s + 1] = NULL;
    return comm;
}

void fix_first_n_last(sh2 *sh)
{
    for (int i = 0; sh->l[i] != 0; i++) {
        if (sh->l[i] != ' ') {
            if (sh->l[i] == ';') {
                sh->l[i] = ' ';
                break;
            } else
                break;
        }
    }
    for (int i = my_strlen(sh->l) - 1; i != 0; i--) {
        if (sh->l[i] != ' ') {
            if (sh->l[i] == ';') {
                sh->l[i] = ' ';
                return;
            } else
                return;
        }
    }
}

void separator(sh2 *sh)
{
    int separator = 0;

    for (int i = 0; sh->l[i] != 0; i++) {
        if (sh->l[i] == ';')
            separator++;
    }
    fix_first_n_last(sh);
    if (separator > 0)
        sh->seperator_comm = split_commands(sh, separator);
    else
        sh->seperator_comm = NULL;
}