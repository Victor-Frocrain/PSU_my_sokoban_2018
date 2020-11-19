/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban
*/

#include "my.h"

void display_readme(void)
{
    char *buff = malloc(sizeof(char) * (SIZE_README + 1));
    int fd = 0;

    if (buff == NULL)
        exit(MY_EXIT_ERROR);
    fd = open("README", O_RDONLY);
    if (fd < 0) {
        free(buff);
        exit(MY_EXIT_ERROR);
    }
    else if (read(fd, buff, SIZE_README) <= 0) {
        free(buff);
        close(fd);
        exit(MY_EXIT_ERROR);
    }
    my_putstr(buff);
    free(buff);
    close(fd);
}

int display_message(int key)
{
    mvaddstr(LINES / 2, COLS / 2 - 29 / 2,
    "Please, enlarge the terminal.");
    refresh();
    key = getch();
    clear();
    return (key);
}

void init_term(void)
{
    WINDOW *win = initscr();

    nodelay(win, true);
    curs_set(0);
    keypad(win, true);
    noecho();
}

void display_string(game *s)
{
    int len = my_strlen(s->place->map);
    int x = 0;
    int y = 0;

    for (int i = 0; s->place->map[i] && s->place->subjects[i]; i++) {
        mvaddch(y, x, s->place->map[i]);
        if (s->place->subjects[i] == 'P' || s->place->subjects[i] == 'X')
            mvaddch(y, x, s->place->subjects[i]);
        if (s->place->map[i] == '\n') {
            y++;
            x = 0;
        }
        else
            x++;
    }
    refresh();
}

int my_sokoban(char **av, game *s)
{
    int key = 0;

    load_map(av[1], s);
    parse_map(s);
    init_term();
    while (key != 27 && check_victory(s) == false) {
        if (COLS < s->nb_cols || LINES < s->nb_lines)
            key = display_message(key);
        else {
            key = getch();
            check_touch(s, key);
            check_reset(av[1], s, key);
            display_string(s);
        }
    }
    free_all(s);
    return (MY_EXIT_SUCCESS);
}
