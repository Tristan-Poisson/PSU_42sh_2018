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

    if (ac != 0) {
        printf("%s", "Invalid argument\n");
        exit(0);
    }
    if (ac == 0)
        ret = exec_file(stdin);
    return (ret);
}
