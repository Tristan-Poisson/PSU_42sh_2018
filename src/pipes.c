/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** pipes experimentation
*/

#include "my_header.h"

int vve(char *inst, char *str)
{
    int ret;
    pid_t pid;
    int wstatus = 0;

    pid = fork();
    if (pid == -1)
        return (84);
    if (pid == 0) {
        ret = execve(inst, w_to_a(str, " "), environ);
        if (ret == -1)
            exit(84);
    }
    waitpid(pid, &wstatus, ret);
    if (WIFSIGNALED(wstatus)) {
        our_put_str(strsignal(WTERMSIG(wstatus)));
        if (WCOREDUMP(wstatus))
            our_put_str(" (core dumped)\n");
    }
    return (ret);
}

int fonction_f(char *inst, char *str)
{
    int pipefd[2];
    int srt = dup(1);
    int ent = dup(0);

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit (84);
    }
    dup2(pipefd[1], 1);
    vve(inst, inst);
    dup2(pipefd[0], 0);
    dup2(srt, 1);
    vve(str, str);
    dup2(ent, 0);
    close(pipefd[0]);
    close(pipefd[1]);
    return (0);
}

int detect_pipe(char **av, int ac)
{
    int i = 0;

    while (i < ac) {
        if (str_cmp(av[i], "|"))
            fonction_f(av[i - 1], av[i + 1]);
        i = i + 1;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    detect_pipe(av, ac);
}
