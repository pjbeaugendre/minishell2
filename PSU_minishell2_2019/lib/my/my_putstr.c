/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** display one-by-one characters
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int x = 0;

    for (x = 0; str[x] != '\0'; x++)
        my_putchar(str[x]);
    return (0);
}