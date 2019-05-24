/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** built in 3
*/

#include "head.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int my_setenv(char **com)
{
    char *arg;
    if (com[2] == NULL)
        arg = "  ";
    else
        arg = strdup(com[2]);
    setenv(com[1], arg, 1);
}

int my_unsetenv(char **com)
{
    if (getenv(com[1]) != NULL) {
        unsetenv(com[1]);
        return (0);
    } else {
        return (0);
    }
}