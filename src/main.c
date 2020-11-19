/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av, char **ae)
{
    game *s = init_struct(s);

    if (ac != 2 || ae == NULL)
        return (MY_EXIT_ERROR);
    else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_readme();
        return (MY_EXIT_SUCCESS);
    }
    return (my_sokoban(av, s));
}
