/*
** EPITECH PROJECT, 2018
** my_intlen
** File description:
** my_intlen
*/

#include "my.h"

int my_intlen(unsigned int nb)
{
    int i = 0;

    for (int j = 1; nb / j > 0; j *= 10)
        i++;
    return (i);
}
