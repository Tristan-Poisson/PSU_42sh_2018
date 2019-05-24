/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** buitlin.c
*/

#include "prototypes.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int echo_next(char **command)
{
    int start = 1;
    int back = 0;

    if (command[1] != NULL && command[2] == NULL &&
    strcmp(command[1], "-n") == 0) {
        return (0);
    }
    if (strcmp(command[1], "-n") == 0) {
        back = 2;
        start = 2;
    }
    printf("%s", command[start]);
    start++;
    for (start; command[start]; start++){
        printf(" ");
        printf("%s", command[start]);
    }
    if (back != 2)
        printf("\n");
    fflush(stdout);
    return (0);
}

int my_echo(char **command)
{
    if (command[1] != NULL) {
        echo_next(command);
        return (0);
    } else
        printf("\n");
    fflush(stdout);
    return (0);
}
