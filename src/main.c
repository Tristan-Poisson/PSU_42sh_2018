/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Main file
*/

#include <stdio.h>

int main(int ac, char **av)
{
    int ret = 0;
    FILE *file;

    if (ac > 2) {
        printf("%s", "Too much argument\n");
        exit(0);
    }
    if (ac == 2) {
        file = fopen(av[1], "r");
        ret = exec_file(file);
    }
    if (ac == 1)
        ret = exec_file(stdin);
    return (ret);
}
