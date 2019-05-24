/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Select how to execute
*/

#include "prototypes.h"
#include "my_builtins.h"
#include <stddef.h>
#include <string.h>

int select_my_exec(char **command)
{
    for (int i = 0; builtins[i] != NULL; i++)
        if (!strcmp(command[0], builtins[i]))
            return (builtins_tab[i](command));
    if (is_path(command[0])) {
        return (my_exec(command, command[0]));
    } else {
        return (find_command(command));
    }
}
