/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** desc
*/

void my_putchar(char c);

int my_put_nbr(long int nb)
{
    int nb2;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(nb2 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}