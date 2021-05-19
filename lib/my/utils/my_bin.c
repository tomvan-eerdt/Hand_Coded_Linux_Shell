/*
** EPITECH PROJECT, 2020
** fs_understand_return_of_read
** File description:
** desc
*/

#include <stdio.h>
#include <stdlib.h>

int char_to_int(char *n);

int  my_strlen(char  const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);

    for (int a = 0, z = len-1; a < z; a++, z--) {
        char save_a = str[a];
        str[a] = str[z];
        str[z] = save_a;
    }
    return (str);
}

int get_len_dec(int k)
{
    int i = 0;

    while (k != 0) {
        k  = k / 2;
        i++;
    }
    return (i);
}

int my_bin(int p)
{
    char bin[get_len_dec(p)];
    int a = 0;

    if (p >= 0) {
        while (p != 0) {
            bin[a] = p % 2 + 48;
            p  = p / 2;
            a++;
        }
        bin[a] = '\0';
    }
    return (char_to_int(my_revstr(bin)));
}