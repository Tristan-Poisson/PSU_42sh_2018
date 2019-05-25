/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** builtin cd
*/

#include "prototypes.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void p_error(void)
{
    fprintf(stderr,"%s", "cd: Too many arguments.\n");
}

void end_cd(char **command)
{
    char * pwd;
    char * oldpwd;

    oldpwd = getenv("PWD");
    pwd = command[1];
    if (chdir(pwd) == -1)
        my_perror(pwd);
    setenv("PWD", pwd, 1);
    setenv("OLDPWD", oldpwd, 1);
}

int next_cd(char **command, int args)
{
    char * pwd;
    char * oldpwd;

    if (args == 1)
        return (84);
    if (strcmp(command[1], "-") == 0) {
        pwd = getenv("OLDPWD");
        oldpwd = getenv("PWD");
        if (chdir(pwd) == -1)
            my_perror(pwd);
        setenv("PWD", pwd, 1);
        setenv("OLDPWD", oldpwd, 1);
        return (0);
    }
    if (args == 2) {
        end_cd(command);
    }
    fflush(stdout);
}

int my_cd(char **command)
{
    int args = 0;
    char *oldpwd;
    char *pwd;

    for (int i = 0; command[i]; i++)
        args++;
    if (args > 2)
        p_error();
    if (args == 1) {
        oldpwd = getenv("PWD");
        pwd = getenv("HOME");
        if (chdir(pwd) == -1)
            my_perror(pwd);
        setenv("PWD", pwd, 1);
        setenv("OLDPWD", oldpwd, 1);
    }

    next_cd(command, args);
    fflush(stdout);
}
