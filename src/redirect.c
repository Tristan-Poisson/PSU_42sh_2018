/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** redirect
*/

#include "prototypes.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int chev(char *file, char **cmd)
{
    int fd = open(file, O_RDWR | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    int rs = dup(1);

    dup2(fd, 1);
    select_my_exec(cmd);
    dup2(1, rs);
    return (0);
}

int d_chev(char *file, char **cmd)
{
    int	fd = open(file, O_RDWR | O_CREAT | O_APPEND,
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    int	rs = dup(1);

    dup2(fd, 1);
    select_my_exec(cmd);
    dup2(1, rs);
    return (0);
}

int chev_op(char *file, char **cmd)
{
    int fd = open(file, O_RDWR);
    int rs = dup(0);

    dup2(fd, 0);
   select_my_exec(cmd);
    dup2(0, rs);
    return (0);
}

int d_chev_op(char *end, char **cmd)
{
    FILE *tmp = tmpfile();
    int fd = fileno(tmp);
    int rs = dup(0);
    char *temp = NULL;
    size_t n = 0;

    while (1) {
        printf("%s", "?");
        if (getline(&temp, &n, stdin) == -1 || strcmp(temp, end) == 0)
            break;
        else
            fprintf(tmp, "%s", temp);
    }
    rewind(tmp);
    dup2(fd, 0);
    select_my_exec(cmd);
    dup2(0, rs);
    return (0);
}
