/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** swap the content of two integers
*/

void my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
}