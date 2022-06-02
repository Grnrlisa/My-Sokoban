/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main fct
*/

#include "my.h"
#include "sokoban.h"

static void static_o(skb_t *skbn)
{
    for (int y = 0, x = 0; y != skbn->nb_o; y++, x++) {
        if (skbn->posP_y == skbn->pos_o[y][1] &&
        skbn->posP_x == skbn->pos_o[x][0])
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = 'O';
    }
}

void moove_left(skb_t *skbn)
{
    if (check_col_left(skbn) == 1) {
        if (skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] == ' ' ||
        skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] == 'O')
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
        if ((skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] == 'X' &&
        skbn->new_buff[skbn->posP_y][skbn->posP_x - 2] == 'X')) {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y][skbn->posP_x - 2] = 'X';
            skbn->new_buff[skbn->posP_y][skbn->posP_x - 3] = 'X';
        }
        if (skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] == 'X' &&
        skbn->new_buff[skbn->posP_y][skbn->posP_x - 2] != '#') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y][skbn->posP_x - 2] = 'X';
        }
        static_o(skbn);
        skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] = 'P';
        skbn->posP_x = skbn->posP_x - 1;
    }
}

void moove_right(skb_t *skbn)
{
    if (check_col_right(skbn) == 1) {
        if (skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] == ' ' ||
        skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] == 'O')
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
        if (skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] == 'X' &&
        skbn->new_buff[skbn->posP_y][skbn->posP_x + 2] == 'X') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y][skbn->posP_x + 2] = 'X';
            skbn->new_buff[skbn->posP_y][skbn->posP_x + 3] = 'X';
        }
        if (skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] == 'X' &&
        skbn->new_buff[skbn->posP_y][skbn->posP_x + 2] != '#') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y][skbn->posP_x + 2] = 'X';
        }
        static_o(skbn);
        skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] = 'P';
        skbn->posP_x = skbn->posP_x + 1;
    }
}

void moove_down(skb_t *skbn)
{
    if (check_col_down(skbn) == 1) {
        if (skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] == ' ' ||
        skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] == 'O')
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
        if (skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] == 'X' &&
        skbn->new_buff[skbn->posP_y + 2][skbn->posP_x] == 'X') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y + 2][skbn->posP_x] = 'X';
            skbn->new_buff[skbn->posP_y + 3][skbn->posP_x] = 'X';
        }
        if (skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] == 'X' &&
        skbn->new_buff[skbn->posP_y + 2][skbn->posP_x] != '#') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y + 2][skbn->posP_x] = 'X';
        }
        static_o(skbn);
        skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] = 'P';
        skbn->posP_y = skbn->posP_y + 1;
    }
}

void moove_up(skb_t *skbn)
{
    if (check_col_up(skbn) == 1) {
        if (skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] == ' ' ||
        skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] == 'O')
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
        if (skbn->new_buff[skbn->posP_y- 1][skbn->posP_x] == 'X' &&
        skbn->new_buff[skbn->posP_y - 2][skbn->posP_x] == 'X') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y - 2][skbn->posP_x] = 'X';
            skbn->new_buff[skbn->posP_y - 3][skbn->posP_x] = 'X';
        }
        if (skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] == 'X' &&
        skbn->new_buff[skbn->posP_y - 2][skbn->posP_x] != '#') {
            skbn->new_buff[skbn->posP_y][skbn->posP_x] = ' ';
            skbn->new_buff[skbn->posP_y - 2][skbn->posP_x] = 'X';
        }
        static_o(skbn);
        skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] = 'P';
        skbn->posP_y = skbn->posP_y - 1;
    }
}
