/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** File with prototypes
*/

#ifndef PROTOTYPES
#define PROTOTYPES

#include <stdio.h>

// exec_file.c
char *recover_line(FILE *file);
int exec_file(FILE* file);

// exec_com.c
char *build_an_access(char *wipath, char *name);
int is_path(char *path);
int find_command(char **command);
int my_exec(char **command, char *path);

// search.c
int select_my_exec(char **command);

// my_error.c
void my_perror(char *name);

// my_str_to_word_array.c
char **my_str_to_word_array(char *str, char *blanks);

// builtin.c
int my_echo(char **command);
int echo_next(char **command);

// buit_in_env.c
int my_setenv(char **command);
int my_unsetenv(char **command);

// built_in_exit.c
int my_exit(char **command);

// my_atoi.c
int my_atoi(char *str);

#endif
