/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** built in 3
*/

#include "prototypes.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int my_setenv(char **command)
{
    char *arg;

    if (command[2] == NULL)
        arg = "";
    else
        arg = strdup(command[2]);
    setenv(command[1], arg, 1);
    return (0);
}

int my_unsetenv(char **command)
{
    if (getenv(command[1]) != NULL) {
        unsetenv(command[1]);
        return (0);
    } else {
        return (0);
    }
}
