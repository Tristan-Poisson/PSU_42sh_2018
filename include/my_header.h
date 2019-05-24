/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** header for the pipes
*/

#ifndef PP
#define PP

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
extern char **environ;

//string.c
int char_cmp(char *str, char c);
char **word_trans(char **ret, char *array, char *dec);
char **w_to_a(char *array, char *dec);
int nb_word(char *array, char *dec);

//pipes.c
int vve(char *inst, char *str);
int fonction_f(char *inst, char *str);
int detect_pipe(char **av, int ac);
int main(int ac, char **av);

//our.c
void our_put_str(char *str);
int str_cmp(char *test, char *verify);

#endif
