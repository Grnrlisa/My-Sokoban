/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lisa.garnier
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stddef.h>

    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    char **my_str_to_word_array(char *str);
    int compare_strings(char const *str1, char const *str2);

#endif/* !MY_H_ */
