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

int redirect_stdin(sh2 *sh, char *file)
{
    sh->stdin_file = open(file, O_RDONLY);

    if (sh->stdin_file != -1) {
        close(STDIN_FILENO);
        dup(sh->stdin_file);
        return 0;
    } else {
        write(1, file, my_strlen(file));
        write(1, ": No such file or directory.\n", 29);
        sh->redi_error = -1;
        sh->command = 1;
    }
    return -1;
}

void check_stdin_redirection(sh2 *sh)
{
    for (int i = 0; sh->l[i] != 0; i++) {
        if (sh->l[i] == '<' && sh->l[i + 1] != '<') {
            sh->stdin_red = 1;
            break;
        }
        else if (sh->l[i] == '<' && sh->l[i + 1] == '<') {
            sh->stdin_red = 2;
            break;
        }
    }
    if (sh->stdin_red == 1) {
        redirect_stdin(sh, rem_spaces(clear_command(sh, '<')));
    }
}