/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_put_nbr Piscine
*/

#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int nb2;

    if (nb < 0) {
        my_putchar(45);
        nb = -nb;
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