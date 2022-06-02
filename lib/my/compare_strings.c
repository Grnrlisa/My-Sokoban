/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** str man
*/

#include "my.h"

int compare_strings(char const *str1, char const *str2)
{
    int i = 0;

    while ((str1[i] != '\0') && (str2[i] != '\0')) {
        if (str1[i] < str2[i])
            return (-1);
        if (str1[i] > str2[i])
            return (1);
        i += 1;
    }
    if ((str1[i] == '\0') && (str2[i] == '\0'))
        return (0);
    else if (str1[i] == '\0')
        return (-1);
    else
        return (1);
}
