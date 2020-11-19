/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** my_memset
*/

#include "my.h"

char *my_memset(char *str, char c, int size)
{
    char *result = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        result[i] = c;
    str = result;
    return (str);
}
