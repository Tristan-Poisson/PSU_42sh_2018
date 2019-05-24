/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** buitlin.c
*/

#include "head.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int echo_next(char **com)
{
    int start = 1;
    int back = 0;

    if (com[1] != NULL && com[2] == NULL && strcmp(com[1], "-n") == 0) {
        return (0);
    }
    if (strcmp(com[1], "-n") == 0) {
        back = 2;
        start = 2;
    }
    printf("%s", com[start]);
    start++;
    for (start; com[start]; start++){
        printf(" ");
        printf("%s", com[start]);
    }
    if (back != 2)
        printf("\n");
    fflush(stdout);
}

int my_echo(char **com)
{
    if (com[1] != NULL) {
        echo_next(com);
        return (0);
    } else
        printf("\n");
    fflush(stdout);
    return (0);
}    
