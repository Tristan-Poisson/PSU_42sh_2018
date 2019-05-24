/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** our functions for the pipes
*/

#include "my_header.h"

void our_put_str(char *str)
{
    int length;

    length = strlen(str);
    write(1, str, length);
}

int str_cmp(char *test, char *verify)
{
    int i = 0;
    int down = 1;

    while (test[i] && verify[i]) {
        if (test[i] == verify[i])
            i = i + 1;
        else {
            down = 0;
            i = i + 1;
        }
    }
    return (down);
}
