/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Builtins
*/

#include "prototypes.h"
#include <stddef.h>

const char *builtins[5] = {"exit", "setenv", "unsetenv", "echo", NULL};
const int (*builtins_tab[5])(char **) = {&my_exit, &my_setenv,
&my_unsetenv, &my_echo, NULL};
