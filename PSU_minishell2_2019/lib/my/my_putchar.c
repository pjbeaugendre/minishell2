/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** show
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}