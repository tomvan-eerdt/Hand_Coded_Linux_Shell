/*
** EPITECH PROJECT, 2020
** fs_understand_return_of_read
** File description:
** desc
*/

int my_strlen(char const *str);

int my_pow(int n, int pow)
{
    for (int i = 0; i != pow; i++) {
        n *= 10;
    }
    return (n);
}

int char_to_int(char *n)
{
    int result = 0;
    for (int i = 0; i != my_strlen(n); i++) {
        result += my_pow(n[(my_strlen(n) - 1) - i] - 48, i);
    }
    return (result);
}