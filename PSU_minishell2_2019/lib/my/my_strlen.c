/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** counts and return the numbers pf characters
*/

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0')
        x++;
    return (x);
}