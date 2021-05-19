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

int check_path_exists(char *path)
{
    struct stat buf;

    return (stat(path, &buf));
}

char **copy_args(int len, char *l)
{
    char **args = malloc(sizeof(char *) * (len + 1));
    char *strToken = strtok(l, " ");
    int o = 0;

    if (args == NULL)
        exit(84);
    while (strToken != NULL) {
        args[o] = malloc(sizeof(char) * my_strlen(strToken));
        if (args[o] == NULL)
            exit(84);
        args[o] = strToken;
        strToken = strtok(NULL, " ");
        o++;
    }
    if (len == 0)
        o++;
    args[o] = NULL;
    return args;
}

char *correct_path(char *arg, char **ev)
{
    struct stat *buf = malloc(sizeof(struct stat));
    char *temp = NULL;
    char *ars = NULL;

    if (buf == NULL)
        exit(84);
    for (int i = 0; ev[i] != NULL; i++) {
        if (compare_strings(strtok(ev[i], "="), "PATH") == 0) {
            temp = strtok(NULL, "=");
            temp = strtok(temp, ":");
            while (temp != NULL) {
                temp = strtok(NULL, ":");
                temp = my_strcat(temp, "/");
                ars = my_strcat(temp, arg);
                if (ars != NULL && stat(ars, buf) == 0)
                    return ars;
            }
            return NULL;
        }
    }
    return NULL;
}

int exec_command(char **ev, char *l, int *command)
{
    int len = count_args(l);
    int pid = fork();

    if (pid == 0)
        child(len, l, ev);
    else if (pid == -1) {
        write(1, "something went wrong\n", 21);
        exit(84);
    } else
        parent(pid, command);
}

void built_in(char **ev, char *l, int *command)
{
    int exit = check_str_contains("unsetenv", l);

    if (check_str_contains("env", l) == 1 && check_str_contains("cd", l) == 1)
        if (check_str_contains("unsetenv", l) == 1 && exit == 1)
            if (check_str_contains("setenv", l) == 1)
                exec_command(ev, l, command);
}