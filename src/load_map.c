/*
** EPITECH PROJECT, 2018
** load_map
** File description:
** load_map
*/

#include "my.h"

void fill_subjects(game *s)
{
    for (int i = 0; s->place->map[i]; i++) {
        if (s->place->map[i] == 'P') {
            s->place->subjects[i] = s->place->map[i];
            s->place->map[i] = ' ';
            s->player = i;
        }
        else if (s->place->map[i] == 'X') {
            s->place->subjects[i] = s->place->map[i];
            s->place->map[i] = ' ';
        }
        else
            s->place->subjects[i] = ' ';
    }
    s->place->subjects[my_strlen(s->place->subjects)] = 0;
}

void fill_buffer(int fd, struct stat info, game *s)
{
    s->place->map = malloc(sizeof(char) * (info.st_size + 1));
    if (s->place->map == NULL) {
        free_all(s);
        exit(MY_EXIT_ERROR);
    }
    s->place->subjects = malloc(sizeof(char) * (info.st_size + 1));
    if (s->place->subjects == NULL) {
        free(s->place->map);
        free_all(s);
        exit(MY_EXIT_ERROR);
    }
    if (read(fd, s->place->map, info.st_size) <= 0) {
        free(s->place->map);
        exit(MY_EXIT_ERROR);
    }
    s->place->map[my_strlen(s->place->map)] = 0;
    fill_subjects(s);
}

void load_map(char *filepath, game *s)
{
    struct stat info;
    int fd = open(filepath, O_RDONLY);

    if (fd < 0)
        exit(MY_EXIT_ERROR);
    stat(filepath, &info);
    fill_buffer(fd, info, s);
    close(fd);
}
