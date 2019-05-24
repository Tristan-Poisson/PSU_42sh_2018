/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** File who execute command
*/

#include "prototypes.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
extern char **environ;

char *build_an_access(char *wipath, char *name)
{
    int len = strlen(wipath);
    int len_max = (strlen(wipath) + strlen(name) + 1);
    char *result = malloc(sizeof(char) * (len_max + 1));
    int pos = 0;

    for (int i = 0; wipath[i] != '\0'; i++)
        result[pos++] = wipath[i];
    if (wipath[len - 1] != '/')
        result[pos++] = '/';
    for (int i = 0; name[i] != '\0'; i++)
        result[pos++] = name[i];
    result[pos] = '\0';
    return (result);
}

int is_path(char *path)
{
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/')
            return (1);
    }
    return (0);
}

int find_command(char **command)
{
    char **path;
    char *to_test;

    path = my_str_to_word_array(getenv("PATH"), ":");
    for (int i = 0; path[i] != NULL; i++) {
        to_test = build_an_access(path[i], command[0]);
        if (!access(to_test, F_OK))
            return (my_exec(command, to_test));
    }
    fprintf(stderr, "%s", command[0]);
    fprintf(stderr, "%s", ": Command not found.\n");
    return (84);
}

int my_exec(char **command, char *path)
{
    pid_t child;
    int wstatus = 0;

    child = fork();
    if (child == -1)
        return (84);
    if (child == 0) {
        execve(path, command, environ);
        my_perror(command[0]);
        exit(84);
    }
    waitpid(child, &wstatus, 0);
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == SIGFPE)
            fprintf(stderr, "%s", "Floating exception");
        else
            fprintf(stderr, "%s", strsignal(WTERMSIG(wstatus)));
        if (WCOREDUMP(wstatus))
            fprintf(stderr, "%s", " (core dumped)\n");
    }
    return (WEXITSTATUS(wstatus));
}
