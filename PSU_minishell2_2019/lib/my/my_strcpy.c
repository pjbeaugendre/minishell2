/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** copies a string another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}