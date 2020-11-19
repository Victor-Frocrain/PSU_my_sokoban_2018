/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "my.h"

game *init_struct(game *s)
{
    s = malloc(sizeof(game));
    if (s == NULL)
        exit(MY_EXIT_ERROR);
    s->coor = malloc(sizeof(coordinates));
    if (s->coor == NULL) {
        free(s);
        exit(MY_EXIT_ERROR);
    }
    s->place = malloc(sizeof(area));
    if (s->place == NULL) {
        free(s->coor);
        free(s);
        exit(MY_EXIT_ERROR);
    }
    s->nb_cols = 0;
    s->nb_boxes = 0;
    s->nb_lines = 0;
    return (s);
}

void free_all(game *s)
{
    endwin();
    if (s->place->map)
        free(s->place->map);
    if (s->place->subjects)
        free(s->place->subjects);
    free(s->coor);
    free(s->place);
    free(s);
}
