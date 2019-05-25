/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** buitlin2.c
*/

#include "prototypes.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void exit_error(void)
{
    write(2, "exit: Expression Syntax.\n", 25);
}

int check_number(char **com)
{
    for (int j = 0; com[1][j] != '\0'; j++)
        if (com[1][j] < 48 || com[1][j] > 57) {
            exit_error();
            return (-1);
        }
    return (0);
}

int my_exit(char **command)
{
    if (command[2]) {
        exit_error();
        return (84);
    }
    if (command[1] == NULL) {
        printf("exit\n");
        exit(0);
    }
    if (check_number(command) != -1)
        exit(atoi(command[1]));
    else
        return (84);
}
