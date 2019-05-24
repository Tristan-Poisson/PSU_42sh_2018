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

int my_exit(char **command)
{
    if (command[2]) {
        my_perror(command[0]);
        return (84);
    }
    if (command[1] == NULL) {
        printf("exit\n");
        exit(0);
    }
    if (my_atoi(command[0]) != -1)
        exit(my_atoi(command[0]));
    else
        return (0);
}
