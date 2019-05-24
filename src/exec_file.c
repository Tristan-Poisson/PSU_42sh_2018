/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** File who execute file
*/

#include <stdio.h>
#include <unistd.h>

char *recover_line(FILE *file)
{
    int fd = fileno(file);
    char *temp = NULL;
    size_t n = 0;

    if (isatty(fd))
        printf("%s", "^-^/~");
    if (getline(&temp, &n, file) == -1)
        return (NULL);
    return (temp);
}

int exec_file(FILE *file)
{
    char *line;
    char **command;
    int ret_t = 0;

    while (line = recover_line(file)) {
        command = my_str_to_word_array(line, " \n\t");
        ret_t = select_my_exec(command);
    }
    return (ret_t);
}
