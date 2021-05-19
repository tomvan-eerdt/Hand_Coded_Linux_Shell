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
#include <sys/wait.h>

#include "../../../include/my.h"
#include "../../../include/myfuncts.h"

char *correct_path(char *arg, char **ev);

void child(int len, char *l, char **ev)
{
    char *path = NULL;
    char **args = copy_args(len, l);
    char *tampon = NULL;

    if (check_path_exists(args[0]) == 0)
        exit(execve(args[0], args, ev));
    else if (check_if_path(args[0]) == 0) {
        path = correct_path(args[0], ev);
        if (path == NULL)
            exit(255);
        exit(execve(path, args, ev));
    }
    if (args[0][0] != '/')
        path = my_strcat(getcwd(tampon, UCHAR_MAX), "/");
    if (path == NULL)
            exit(255);
    exit(execve(my_strcat(path, args[0]), args, ev));
}

void parent(int pid, int *command)
{
    int exit_s = 0;

    waitpid(pid, &exit_s, 0);
    if (WIFSIGNALED(exit_s))
        write(1, "Segmentation fault (core dumped)\n", 33);
    if (!WSTOPSIG(exit_s) || WEXITSTATUS(exit_s) != 255)
        *command = 1;
}
