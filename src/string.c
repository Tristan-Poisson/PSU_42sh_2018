/*
** EPITECH PROJECT, 2019
** 42 sh
** File description:
** function who do stuff to string
*/

#include "my_header.h"

int char_cmp(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return (1);
        else
            i = i + 1;
    }
    return (0);
}

char **word_trans(char **ret, char *array, char *dec)
{
    int compt[4] = {0, 0, 0, 0};
    int swit = 0;

    while (array[compt[0]] != '\0') {
        if (char_cmp(dec, array[compt[0]]) && swit == 1) {
            ret[compt[1]][compt[2]] = '\0';
            compt[1] = compt[1] + 1;
            compt[0] = compt[0] + 1;
            compt[2] = 0;
            compt[4] = 0;
            swit = 0;
        } else if (char_cmp(dec, array[compt[0]]) && swit == 0)
            compt[0] = compt[0] + 1;
        else {
            swit = 1;
            ret[compt[1]][compt[2]] = array[compt[0]];
            compt[2] = compt[2] + 1;
            compt[0] = compt[0] + 1;
            compt[3] = compt[3] + 1;
        }
        compt[3] = 0;
    }
    ret[compt[1]][compt[2]] = '\0';
    return (ret);
}

char **w_to_a(char *array, char *dec)
{
    int i = 0;
    char **ret;
    int nb;
    int lg;

    lg = strlen(array);
    nb = nb_word(array, dec);
    ret = malloc(sizeof(char *) * (nb + 1));
    ret[nb] = NULL;
    while (i < nb) {
        ret[i] = malloc(sizeof(char) * lg);
        i = i + 1;
    }
    return (word_trans(ret, array, dec));
}

int nb_word(char *array, char *dec)
{
    int i = 0;
    int ret = 1;
    int swit = 0;

    while (array[i] != '\0') {
        if (char_cmp(dec, array[i]) && swit == 0)
            i = i + 1;
        else if (char_cmp(dec, array[i]) && swit == 1) {
            ret = ret + 1;
            i = i + 1;
            swit = 0;
        }
        else {
            i = i + 1;
            swit = 1;
        }
    }
    return (ret);
}
