/*
** EPITECH PROJECT, 2018
** my_put_str.c
** File description:
** displays characters
*/

#include "my.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
