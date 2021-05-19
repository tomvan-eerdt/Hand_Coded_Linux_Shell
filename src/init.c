/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include "../include/my.h"
#include "../include/myfuncts.h"
#include <zconf.h>
#include <stdlib.h>

void reset_vars(sh2 *s)
{
    s->command = 0;
    s->redirect = 0;
    s->l = NULL;
    s->file = 0;
    s->ve = NULL;
}

sh2 *init(char **ev)
{
    sh2 *s = malloc(sizeof(sh2));
    s->save_stdout = dup(STDOUT_FILENO);
    s->save_stdin = dup(STDIN_FILENO);
    s->command = 0;
    s->redirect = 0;
    s->redi_error = 0;
    s->ev = ev;
    s->stdin_red = 0;
    s->l = NULL;
    s->file = 0;
    s->ve = NULL;
    return s;
}