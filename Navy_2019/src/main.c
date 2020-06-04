/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
*/

#include "navy.h"

int help(void)
{
    putstr(file_to_str("assets/help"));
    return (0);
}

int navy(int ac, char **av, char *str)
{
    char **p_grid = make_map(str);
    char **hit_grid = make_grid();
    int ret;

    if (p_grid == NULL || hit_grid == NULL)
        return (84);
    get_userpid(ac, av);
    ret = gameloop(p_grid, hit_grid);
    freearray((void **)p_grid);
    freearray((void **)hit_grid);
    return (ret);
}

int main(int ac, char **av)
{
    int ret;
    char *str = NULL;

    if (!(2 <= ac && ac <= 3))
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        return (help());
    str = file_to_str(av[ac - 1]);
    if (str == NULL)
        return (84);
    ret = navy(ac, av, str);
    return (ret);
}