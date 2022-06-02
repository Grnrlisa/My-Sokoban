/*
** EPITECH PROJECT, 2021
** putstr
** File description:
** print une string
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
