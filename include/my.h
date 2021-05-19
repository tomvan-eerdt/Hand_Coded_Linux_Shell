/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

typedef struct qv{
    char *ev;
    struct qv *next;
}v;

int compare_strings(char *str1, char *str2);

int my_strlen(char const *str);

char *my_strcat(char *dest , char *src);

void go_one_step_back(char *path);

int check_spaces(const char *str);

int ls(int ac, char **av);

int searchdir(char *path);

int check_str_contains(char *str, char *str2);

char *check_back_path(char *s);

char *copy_part_str(char *str, int a);

int compare_part_str(char *str, char *str2, int part);

int my_getnbr(char const *str);

char *exec_path(char *str);

int my_put_nbr(long int nb);

int check_path_exists(char *path);

char *rem_spaces(char *str);

char *get_home_dir(char **ev);

v *create_node(char *e);

char *my_strcpy(char *str_to_cpy);

typedef struct mysh2{
    char *curr_path;
    v *ve;
    int command;
    char **ev;
    char *l;
    int redirect;
    int stdin_red;
    int file;
    int stdin_file;
    int save_stdout;
    int save_stdin;
    int redi_error;
    char **seperator_comm;
}sh2;