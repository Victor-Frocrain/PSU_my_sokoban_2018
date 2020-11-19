/*
** EPITECH PROJECT, 2018
** check_victory
** File description:
** check_victory
*/

#include "my.h"

void check_defeat(game *s)
{
    int stucks = 0;
    int k = s->nb_cols;

    for (int i = 0; s->place->subjects[i] && s->place->map[i]; i++) {
        if (s->place->subjects[i] == 'X' && s->place->map[i] != 'O' &&
            ((s->place->map[i - 1] == '#' ||
            s->place->subjects[i - 1] == 'X' ||
            s->place->map[i + 1] == '#' || s->place->subjects[i + 1] == 'X') &&
            (s->place->map[i - k] == '#' || s->place->subjects[i - k] == 'X' ||
            s->place->map[i + k] == '#' || s->place->subjects[i + k] == 'X')))
            stucks++;
        if (stucks == s->nb_boxes) {
            free_all(s);
            exit(MY_EXIT_DEFEAT);
        }
    }
}

bool check_victory(game *s)
{
    check_defeat(s);
    for (int i = 0; s->place->map[i] && s->place->subjects[i]; i++) {
        if (s->place->map[i] == 'O' && s->place->subjects[i] != 'X')
            return (false);
    }
    return (true);
}
