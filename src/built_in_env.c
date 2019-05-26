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
#include <errno.h>

int letter(char c, int low, int up)
{
    if (c > low && c < up)
        return (1);
    else
        return (0);
}

int catch_error(char **command)
{
    if (!letter(command[1][0], 65, 90) && !letter(command[1][0], 97, 122)) {
        printf("setenv: Variable name must begin with a letter.\n");
        return (-1);
    }
    return (0);
}

int my_setenv(char **command)
{
    char *arg;
    int args = 0;

    for (int i = 0; command[i]; i++)
        args++;
    if (args > 3) {
        printf("setenv: Too many arguments.\n");
        return (84);
    }
    if (catch_error(command) == -1) {
        return (84);
    }
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
