/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "prototypes.h"
#include <stdlib.h>

int is_in(char c, char *blanks)
{
    for (int i = 0; blanks[i] != '\0'; i++) {
        if (c == blanks[i])
            return (1);
    }
    return (0);
}

int is_first_word(char *str, char *blanks)
{
    if (!is_in(str[0], blanks))
        return (1);
    return (0);
}

int count_word(char *str, char *blanks)
{
    int count = is_first_word(str, blanks);

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_in(str[i], blanks) &&
        (!is_in(str[i + 1], blanks) && str[i + 1] != '\0'))
            count++;
    }
    return (count);
}

char **my_str_to_word_array(char *str, char *blanks)
{
    char *copy = strdup(str);
    int word = count_word(copy, blanks);
    char **word_array = malloc(sizeof(char *) * (word + 1));
    int count = 0;

    if (is_first_word(copy, blanks)) {
        word_array[count] = copy;
        count++;
    }
    for (int i = 0; copy[i] != '\0'; i++) {
        if (is_in(copy[i], blanks) && !is_in(copy[i + 1], blanks)) {
            word_array[count] = copy + i + 1;
            count++;
        }
        if (is_in(copy[i], blanks))
            copy[i] = '\0';
    }
    word_array[word] = NULL;
    return (word_array);
}
