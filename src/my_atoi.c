/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** 
*/

#include <stddef.h>

int my_atoi(char *str)
{
    int result = 0;

    if (str == NULL)
        return (-1);
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] < 48 || str[count] > 57)
            return (-1);
        result = result * 10 + str[count] - '0';
    }
    return (result);
}
