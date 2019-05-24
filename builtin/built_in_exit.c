/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** buitlin2.c
*/

#include "head.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void exit_error(void)
{
    write(2, "exit: Expression Syntax.\n", 25);
}

int check_number(char **com)
{
    for (int j = 0; com[1][j] != '\0'; j++) {
        if (com[1][j] < 48 || com[1][j] > 57) {
            exit_error();
            return (-1);
        }
    }
    return (0);
}

int my_exit(char **com)
{
    if (com[2]) {
        exit_error();
        return (84);
    }
    if (com[1] == NULL) {
        printf("exit\n");
        exit(0);
    }
    if (check_number(com) != -1)
        exit(atoi(com[1]));
    else
        return (0);
}