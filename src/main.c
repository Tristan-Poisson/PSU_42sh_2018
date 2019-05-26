/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Main file
*/

#include "prototypes.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    int ret = 0;
    FILE *file;

    if (ac > 2) {
        printf("%s", "Too much argument\n");
        exit(0);
    }
    if (ac == 2) {
        if (!access(av[1], R_OK)) {
            file = fopen(av[1], "r");
            ret = exec_file(file);
        } else {
            fprintf(stderr, "%s", "Can't read file\n");
            exit(0);
        }
    }
    if (ac == 1)
        ret = exec_file(stdin);
    return (ret);
}
