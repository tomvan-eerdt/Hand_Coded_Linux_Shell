/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "../../include/my.h"
#include "../../include/myfuncts.h"

int index_start(sh2 *sh, char c)
{
    int access = 0;

    if (sh->stdin_red == 1 || sh->redirect == 1)
        access = 1;
    if (sh->stdin_red == 2 || sh->redirect == 2)
        access = 2;
    for (int j = 0; sh->l[j] != 0; j++){
        if (access == 2 && sh->l[j] == c && sh->l[j + 1] == c)
            return j + 2;
        if (access == 1 && sh->l[j] == c && sh->l[j + 1] != c)
            return j + 1;
    }
}

char *clear_command(sh2 *sh, char c)
{
    int i = 0;
    int v = 0;
    int a = 0;
    char *file_name = malloc(sizeof(char) * my_strlen(sh->l));

    for (int j = index_start(sh, c); sh->l[j] != 0; j++) {
        file_name[v] = sh->l[j];
        v++;
    }
    file_name[v] = 0;
    for (; sh->l[i] != c; i++){}
    sh->l[i] = 0;
    return clean_str(file_name);
}

void check_redirect(sh2 *sh)
{
    for (int i = 0; sh->l[i] != 0; i++) {
        if (sh->l[i] == '>' && sh->l[i + 1] != '>') {
            sh->redirect = 1;
            break;
        }
        else if (sh->l[i] == '>' && sh->l[i + 1] == '>') {
            sh->redirect = 2;
            break;
        }
    }
    if (sh->redirect == 1) {
        sh->file = open(rem_spaces(clear_command(sh, '>')),
                O_WRONLY | O_TRUNC | O_CREAT, 0777);
        dup2(sh->file, STDOUT_FILENO);
    }
    else if (sh->redirect == 2) {
        sh->file = open(rem_spaces(clear_command(sh, '>')),
                O_WRONLY | O_APPEND | O_CREAT, 0777);
        dup2(sh->file, STDOUT_FILENO);
    }
}

void stop_redirect(sh2 *sh)
{
    if (sh->redirect != 0) {
        dup2(sh->save_stdout, STDOUT_FILENO);
        close(sh->file);
        sh->redirect = 0;
    }
    if (sh->stdin_red != 0) {
        dup2(sh->save_stdin, STDIN_FILENO);
        if (sh->stdin_file != -1)
            close(sh->stdin_file);
        sh->stdin_red = 0;
    }
    sh->redi_error = 0;
}