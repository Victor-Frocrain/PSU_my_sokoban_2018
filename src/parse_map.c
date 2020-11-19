/*
** EPITECH PROJECT, 2018
** parse_map
** File description:
** parse_map
*/

#include "my.h"

void check_last_line(game *s, int i)
{
    if (s->nb_lines < 3) {
        free_all(s);
        exit(MY_EXIT_ERROR);
    }
    if (s->place->map[i + s->nb_cols - 1] != '\n') {
        free_all(s);
        exit(MY_EXIT_ERROR);
    }
    for (; s->place->map[i] && s->place->map[i] != '\n'; i++)
        if (s->place->map[i] != '#') {
            free_all(s);
            exit(MY_EXIT_ERROR);
        }
}

void check_len_line(game *s)
{
    int i = 0;

    for (; s->place->map[s->nb_cols] && s->place->map[s->nb_cols] != '\n';
        s->nb_cols++)
        if (s->place->map[s->nb_cols] != '#') {
            free_all(s);
            exit(MY_EXIT_ERROR);
        }
    s->nb_cols++;
    for (; s->place->map[i]; i++) {
        if (s->place->map[i] == '\n' && s->place->map[i + 1] &&
        i + 1 != (s->nb_lines + 1) * s->nb_cols) {
            free_all(s);
            exit(MY_EXIT_ERROR);
        }
        else if (s->place->map[i] == '\n')
            s->nb_lines++;
    }
    check_last_line(s, i - s->nb_cols);
}

void parse_map(game *s)
{
    int nb_players = 0;
    int nb_wholes = 0;

    check_len_line(s);
    for (int i = 0; s->place->map[i]; i++) {
        if (!((s->place->map[i] == ' ' || s->place->map[i] == '#' ||
        s->place->map[i] == 'O' || s->place->map[i] == '\n') &&
        (s->place->subjects[i] == 'X' || s->place->subjects[i] == 'P' ||
        s->place->subjects[i] == ' '))) {
            free_all(s);
            exit(MY_EXIT_ERROR);
        }
        nb_players += count_players(s->place->subjects[i]);
        s->nb_boxes += count_boxes(s->place->subjects[i]);
        nb_wholes += count_wholes(s->place->map[i]);
    }
    check_number_elements(nb_players, nb_wholes, s);
}
