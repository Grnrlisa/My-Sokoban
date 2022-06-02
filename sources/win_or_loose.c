/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main fct
*/

#include "my.h"
#include "sokoban.h"

static void win_cond(skb_t *skbn)
{
    skbn->win_checker = 0;

    for (int a = 0, b = 0; a != skbn->nb_o && b != skbn->nb_o;) {
        if (skbn->new_buff[skbn->pos_o[b++][1]][skbn->pos_o[a++][0]] == 'X')
            skbn->win_checker++;
    }
    if (skbn->win_checker == skbn->nb_o)
        skbn->win = 1;
}

static void loose_cond(skb_t *skbn, int x, int y)
{
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y - 1][x] == '#' &&
    skbn->new_buff[y][x - 1] == '#' && skbn->win_checker == 0)
        skbn->win = 2;
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y + 1][x] == '#' &&
    skbn->new_buff[y][x + 1] == '#' && skbn->win_checker == 0)
        skbn->win = 2;
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y - 1][x] == '#' &&
    skbn->new_buff[y][x + 1] == '#' && skbn->win_checker == 0)
        skbn->win = 2;
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y + 1][x] == '#' &&
    skbn->new_buff[y][x - 1] == '#' && skbn->win_checker == 0)
        skbn->win = 2;
}

void win_or_loose(skb_t *skbn)
{
    for (int y = 0; y != skbn->height; y++) {
        for (int x = 0; x != skbn->len; x++) {
            win_cond(skbn);
            loose_cond(skbn, x, y);
        }
    }
}
