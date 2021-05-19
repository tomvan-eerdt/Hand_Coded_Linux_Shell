/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "../../include/my.h"
#include "../../include/myfuncts.h"

void check_error(char *file)
{
    struct stat *s;

    write(1, file, my_strlen(file));
    if (stat(file, s) == -1) {
        write(1, ": No such file or directory.\n", 29);
        return;
    }
    if (S_ISDIR(s->st_mode) == 0)
        write(1, ": Not a directory.\n", 19);
}

void get_name(v *temp, char *path)
{
    int q = -1;

    for (int i = 0; temp->ev[i] != 0; i++) {
        if (q >= 0) {
            path[q] = temp->ev[i];
            q++;
        }
        if (temp->ev[i] == '=')
            q = 0;
    }
    path[q] = 0;
}

void handle_cd_dash(sh2 *sh)
{
    int pos = find_env(sh->ve, "OLDPWD");
    v *temp = sh->ve;
    char *path = NULL;

    if (pos == -1)
        write(1, ": No such file or directory.\n", 29);
    else {
        for (int i = 0; i != pos; i++)
            temp = temp->next;
        path = malloc(sizeof(char) * my_strlen(temp->ev));
        get_name(temp, path);
        chdir(path);
    }
}

void handle_cases(sh2 *sh, char **args, char **oldpwd)
{
    if (args[1][0] == '-' && args[1][1] == 0) {
        handle_cd_dash(sh);
        handle_env(oldpwd, 3, &sh->ve);
    }
    else if (chdir(args[1]) != 0)
        check_error(args[1]);
    else
        handle_env(oldpwd, 3, &sh->ve);
}

void cd(sh2 *sh)
{
    int args_n = 0;
    char **args = NULL;
    char *oldpwd[] = {"setenv", "OLDPWD", sh->curr_path};

    if (check_str_contains("cd", sh->l) == 0) {
        args_n = count_args(sh->l);
        args = copy_args(args_n, sh->l);
        if (args_n == 1) {
            handle_env(oldpwd, 3, &sh->ve);
            chdir(get_home_dir(sh->ev));
            sh->command = 1;
            return;
        }
        if (args_n != 2) {
            write(1, "cd: Too many arguments.\n", 24);
            sh->command = 1;
            return;
        }
        handle_cases(sh, args, oldpwd);
        sh->command = 1;
    }
}