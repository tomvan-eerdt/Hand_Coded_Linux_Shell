/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

char *handle_cd(char *line, char *path);

void env(v *ve, char *l , int *command);

void setev(v **ve, char *l, int *command);

void built_in(char **ev, char *l, int *command);

char **copy_and_remove(int pos, char **env);

char *clean_str(char *str);

int redirect_stdin(sh2 *sh, char *file);

void check_stdin_redirection(sh2 *sh);

int count_args(const char *line);

char **copy_args(int len, char *l);

void unsetev(v **ev, char *l, int *command);

void cd(sh2 *sh);

void pwd(char *l, char *s, int *command);\

int count_envs(char **env);

void exit_minis(char *l, int *command);

int count_envs(char **env);

void child(int len, char *l, char **ev);

void parent(int pid, int *command);

v *create_node(char *e);

_Noreturn void minishell1(int ac, char **av, char **ev);

int find_env(v *ev, char *l);

void check_redirect(sh2 *sh);

void stop_redirect(sh2 *sh);

int check_if_path(char *str);

sh2 *init(char **ev);

int replace_if_exists(v **ve, char *name, char *value);

char *clear_command(sh2 *sh, char c);

char *replace_home(char *path);

void reset_vars(sh2 *s);

void handle_env(char **ar, int args_n, v **ve);

void create_env(int args_n, v **ve, char *ar);

void separator(sh2 *sh);