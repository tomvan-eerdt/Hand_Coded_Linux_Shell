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

#include "include/my.h"
#include "include/myfuncts.h"

char *curr_path;

void h_argument(void)
{
    write(1, "Name: Minishell1\n", 17);
    write(1, "Module: B1 - Unix System Programming (Part II)\n", 47);
    write(1, "Arguments: -h\n", 14);
    write(1, "Description: A hand coded linux shell, ", 39);
    write(1, "all the executable in PATH variable are available.\n", 50);
    write(1, "\nThe cd, setenv, env, unsetenv and exit command", 46);
    write(1, "are hand coded.\n\n", 17);
}

int main(int ac, char **av, char **ev)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        h_argument();
    else
        minishell1(ac, av, ev);
    return 0;
}