/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Error file
*/

#include <string.h>
#include <errno.h>
#include <stdio.h>

void my_perror(char *name)
{
    fprintf(stderr, "%s: %s.\n", name, strerror(errno));
}
