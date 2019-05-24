/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** File with prototypes
*/

#ifndef PROTOTYPES
#define PROTOTYPES

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

#endif
