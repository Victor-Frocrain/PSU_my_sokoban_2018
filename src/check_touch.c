/*
** EPITECH PROJECT, 2018
** check_touch
** File description:
** check_touch
*/

#include "my.h"

int detect_boxes(game *s, int incr)
{
    if (s->place->subjects[s->player + incr] == 'X' &&
    s->place->map[s->player + 2 * incr] &&
    (s->place->map[s->player + 2 * incr] == ' ' ||
    s->place->map[s->player + 2 * incr] == 'O')) {
        s->place->subjects[s->player + incr] = ' ';
        s->place->subjects[s->player + 2 * incr] = 'X';
        return (incr);
    }
    else if (s->place->subjects[s->player + incr] != 'X')
        return (incr);
    return (0);
}

int detect_touch(game *s, int key)
{
    int incr = 0;

    switch (key) {
    case KEY_RIGHT:
        incr = 1;
        break;
    case KEY_LEFT:
        incr = -1;
        break;
    case KEY_UP:
        incr = s->nb_cols * -1;
        break;
    case KEY_DOWN:
        incr = s->nb_cols;
        break;
    default:
        break;
    }
    return (incr);
}

void check_touch(game *s, int key)
{
    int incr = detect_touch(s, key);

    if (s->place->map[s->player + incr] &&
    s->place->map[s->player + incr] != '#') {
        if (s->place->subjects[s->player + incr] == 'X' &&
            s->place->subjects[s->player + 2 * incr] == 'X')
            incr = 0;
        if (s->place->map[s->player + incr] == '\n')
            incr = 0;
        s->place->subjects[s->player] = ' ';
        incr = detect_boxes(s, incr);
        s->player += incr;
    }
    s->place->subjects[s->player] = 'P';
}

void check_reset(char *str, game *s, int key)
{
    if (key == KEY_SPACE) {
        free_all(s);
        s = init_struct(s);
        load_map(str, s);
        parse_map(s);
        init_term();
    }
}
