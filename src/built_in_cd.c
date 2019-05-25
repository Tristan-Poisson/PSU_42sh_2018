/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** builtin cd
*/

#include "head.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int p_error(void)
{
    write(2, "cd: Too many arguments.\n", 24);
}

void my_perror(char *name)
{
    my_putstr(name, 2);
    my_putstr(": ", 2);
    my_putstr(strerror(errno), 2);
    my_putstr(".\n", 2);
}

int end_cd(char **com)
{
    char * pwd;
    char * oldpwd;

    oldpwd = getenv("PWD");
    pwd = com[1];
    if (chdir(pwd) == -1)
        my_perror(pwd);
    setenv("PWD", pwd, 1);
    setenv("OLDPWD", oldpwd, 1);
}

int next_cd(char **com, int args)
{
    char * pwd;
    char * oldpwd;

    if (args == 1)
        return (84);
    if (strcmp(com[1], "-") == 0) {
        pwd = getenv("OLDPWD");
        oldpwd = getenv("PWD");
        if (chdir(pwd) == -1)
            my_perror(pwd);
        setenv("PWD", pwd, 1);
        setenv("OLDPWD", oldpwd, 1);
        return (0);
    }
    if (args == 2) {
        end_cd(com);
    }
    fflush(stdout);
}

int my_cd(char **com)
{
    int args = 0;
    char *oldpwd;
    char *pwd;

    for (int i = 0; com[i]; i++)
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

    next_cd(com, args);
    fflush(stdout);
}