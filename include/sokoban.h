/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** my
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stddef.h>

    typedef struct sokoban {
        char *file;
        int fd;
        char *buff;
        char **new_buff;

        int height;
        int len;

        int posP_x;
        int posP_y;

        int nb_o;
        int check_o;
        int **pos_o;
        int win_checker;
        int win;
    } skb_t;

    int start_sokoban(skb_t *skbn);
    void find_size(skb_t *skbn);
    int check_file(skb_t *skbn);

    void find_pos_player(skb_t *skbn);
    void find_pos_o(skb_t *skbn);

    void draw_map(skb_t *skbn);
    void draw_endings(skb_t *skbn);

    void moove_up(skb_t *skbn);
    void moove_down(skb_t *skbn);
    void moove_right(skb_t *skbn);
    void moove_left(skb_t *skbn);

    int check_col_left(skb_t *skbn);
    int check_col_right(skb_t *skbn);
    int check_col_up(skb_t *skbn);
    int check_col_down(skb_t *skbn);

    void win_or_loose(skb_t *skbn);
    char **str_to_tab(char *str);

#endif/* !SOKOBAN_H_ */
