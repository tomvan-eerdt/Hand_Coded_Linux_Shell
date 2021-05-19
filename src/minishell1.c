/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "../include/my.h"
#include "../include/myfuncts.h"

void fill_struct(char **ev, v **head)
{
    v *temp = NULL;
    int i;

    for (i = count_envs(ev) - 1; i != -1; i--) {
        temp = create_node(ev[i]);
        temp->next = (*head);
        (*head) = temp;
    }
}

void display_info(int *command, size_t *len, char **l, char *curr_path)
{
    *command = 0;
    write(1, "tom.ve:", 7);
    write(1, replace_home(curr_path), my_strlen(replace_home(curr_path)));
    write(1, "$> ", 3);
    if (getline(l, len, stdin) == -1) {
        write(1, "exit\n", 5);
        exit(0);
    }
    if (my_strlen(*l) == 1 && *l[0] == '\n')
        display_info(command, len, l, curr_path);
}

void handler(int num)
{
    char *tampon = NULL;
    char *p = replace_home(getcwd(tampon, UCHAR_MAX));

    if (num == 2) {
        write(1, "\ntom.ve:", 8);
        write(1, p, my_strlen(p));
        write(1, "$> ", 3);
    }
}

void commands(sh2 *sh)
{
    check_redirect(sh);
    check_stdin_redirection(sh);
    if (sh->redi_error == 0) {
        exit_minis(sh->l, &sh->command);
        built_in(sh->ev, sh->l, &sh->command);
        unsetev(&sh->ve, sh->l, &sh->command);
        setev(&sh->ve, sh->l, &sh->command);
        cd(sh);
        env(sh->ve, sh->l, &sh->command);
    }
    stop_redirect(sh);
    if (sh->command == 0) {
        write(1, sh->l, my_strlen(sh->l));
        write(1, ": Command not found.\n", 21);
    }
}

void minishell1(int ac, char **av, char **ev)
{
    char *tampon = NULL;
    sh2 *sh = init(ev);
    size_t len = 0;

    signal(SIGINT, handler);
    fill_struct(ev, &sh->ve);
    while (1) {
        sh->curr_path = getcwd(tampon, UCHAR_MAX);
        display_info(&sh->command, &len, &sh->l, sh->curr_path);
        sh->l[my_strlen(sh->l) - 1] = 0;
        separator(sh);
        if (sh->seperator_comm != NULL)
            for (int  i = 0; sh->seperator_comm[i] != NULL; i++) {
                sh->l = clean_str(sh->seperator_comm[i]);
                commands(sh);
            }
        else {
            sh->l = clean_str(sh->l);
            commands(sh);
        }
    }
}