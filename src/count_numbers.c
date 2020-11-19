/*
** EPITECH PROJECT, 2018
** count_numbers
** File description:
** count_numbers
*/

#include "my.h"

int count_players(char c)
{
    if (c == 'P')
        return (1);
    return (0);
}

int count_boxes(char c)
{
    if (c == 'X')
        return (1);
    return (0);
}

int count_wholes(char c)
{
    if (c == 'O')
        return (1);
    return (0);
}

void check_number_elements(int nb_players, int nb_wholes, game *s)
{
    if (nb_players != 1 || s->nb_boxes > nb_wholes) {
        free_all(s);
        exit(MY_EXIT_ERROR);
    }
}
