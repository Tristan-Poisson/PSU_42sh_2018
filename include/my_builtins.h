/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Builtins
*/

#include "prototypes.h"
#include <stddef.h>

const char *builtins[6] = {"cd", "exit", "setenv", "unsetenv", "echo", NULL};
const int (*builtins_tab[6])(char **) = {&my_cd, &my_exit, &my_setenv,
&my_unsetenv, &my_echo, NULL);
