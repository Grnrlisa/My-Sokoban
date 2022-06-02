/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** decoupe en mot uen suite
*/

#include "my.h"

int my_strlen(char const *str);

int nb_column(char *map_char, int nb)
{
    int a = 0;
    int count = 0;

    while (nb != 0) {
        while (map_char[a] != '\n' && map_char[a] != '\0')
            a++;
        a += 2;
        nb--;
    }
    while (map_char[a] != '\n' && map_char[a] != '\0') {
        a++;
        count++;
    }
    return (count);
}

char **my_mall(char *map_char)
{
    char **stock;
    int nb_lines = 0;

    for (int a = 0; map_char[a] != '\0'; a++) {
        if (map_char[a] == '\n')
            nb_lines += 1;
    }
    stock = malloc(sizeof(char *) * (nb_lines + 1));
    if (stock == NULL)
        return (NULL);
    for (int nb = 0; nb < nb_lines; nb++) {
        stock[nb] = malloc(sizeof(int) * (nb_column(map_char, nb) + 1));
        if (stock[nb] == NULL)
            return (NULL);
    }
    stock[nb_lines] = NULL;
    return (stock);
}

char **my_str_to_word_array(char *str)
{
    char **stock;
    int a = 0;
    int b = 0;
    int c = 0;

    if (str == NULL)
        return (NULL);
    stock = my_mall(str);
    while (str[a] != '\0') {
        for (; str[a] != '\n' && str[a] != '\0'; c++) {
            stock[b][c] = str[a];
            a++;
        }
        stock[b][c] = '\n';
        a++;
        b++;
        c = 0;
    }
    stock[b] = NULL;
    return (stock);
}
