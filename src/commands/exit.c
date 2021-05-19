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

#include "../../include/my.h"
#include "../../include/myfuncts.h"

int check_if_number(const char *arg)
{
    for (int i = 0; arg[i] != 0; i++) {
        if (arg[i] < '0' || arg[i] > '9')
            return 1;
    }
    return 0;
}

void exit_minis(char *l, int *command)
{
    int args_n = 0;
    char **args = NULL;

    if (check_str_contains("exit", l) == 0) {
        args_n = count_args(l);
        args = copy_args(args_n, l);
        write(1, "exit", 4);
        if (args_n == 1) {
            write(1, "\n", 1);
            exit(5);
        } else if (args_n == 2 && check_if_number(args[1]) == 0) {
            write(1, "\n", 1);
            exit(my_getnbr(args[1]));
        } else {
            write(1, ": Expression Syntax.", 20);
        }
        write(1, "\n", 1);
        *command = 1;
    }
}