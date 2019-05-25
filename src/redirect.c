/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** redirect
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int chev(char *file, char **cmd)
{
    int fd = open(file, O_RDWR | O_CREAT,
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    int rs = dup(1);

    dup2(fd, 1);
    write(1, "test2\n", 6);
    dup2(1, rs);
    return (0);
}

int d_chev(char *file, char **cmd)
{
    int	fd = open(file, O_RDWR | O_CREAT | O_APPEND,
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    int	rs = dup(1);

    dup2(fd, 1);
    write(1, "test2\n", 6);
    dup2(1, rs);
    return (0);
}

int chev_op(void)
{
    return (0);
}

int d_chev_op(void)
{
    return (0);
}
