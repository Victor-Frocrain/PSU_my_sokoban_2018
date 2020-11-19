/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <curses.h>
#include <fcntl.h>

#ifndef MY_H_
#define MY_H_
#define MY_EXIT_ERROR (84)
#define MY_EXIT_DEFEAT (1)
#define MY_EXIT_SUCCESS (0)
#define KEY_SPACE ' '
#define SIZE_README 182

struct coordinates_s {
    int x;
    int y;
};

struct area_s {
    char *map;
    char *subjects;
};

typedef struct coordinates_s coordinates;
typedef struct area_s area;

struct game_s {
    coordinates *coor;
    area *place;
    int nb_cols;
    int nb_boxes;
    int nb_lines;
    int player;
};

typedef struct game_s game;
void load_map(char *filepath, game *s);
game *init_struct(game *s);
void free_all(game *s);
void parse_map(game *s);
int count_players(char c);
int count_boxes(char c);
int count_wholes(char c);
void check_number_elements(int nb_players, int nb_wholes, game *s);
void check_touch(game *s, int key);
bool check_victory(game *s);
int my_sokoban(char **av, game *s);
void display_readme(void);
void init_term(void);
void check_reset(char *str, game *s, int key);

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char *str);
char *my_memset(char *str, char c, int size);
int my_intlen(unsigned int nb);

#endif /* MY_H_ */
