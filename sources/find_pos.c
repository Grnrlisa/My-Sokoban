/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** file fct
*/

#include "my.h"
#include "sokoban.h"

static int fill_int_array(skb_t *skbn, int y, int x, int nb_o)
{
    if (skbn->new_buff[y][x] == 'O') {
        skbn->pos_o[nb_o] = malloc(sizeof(int) * 2);
        skbn->pos_o[nb_o][0] = x;
        skbn->pos_o[nb_o][1] = y;
        nb_o++;
    }
    return (nb_o);
}

void find_pos_o(skb_t *skbn)
{
    int nb_o = 0;

    for (int y = 0; skbn->buff[y] != '\0'; y++) {
        if (skbn->buff[y] == 'O')
            nb_o++;
        }
    skbn->pos_o = malloc(sizeof(int *) * (nb_o + 1));
    skbn->pos_o[nb_o] = NULL;
    nb_o = 0;
    for (int y = 0; skbn->new_buff[y] != NULL; y++) {
        for (int x = 0; skbn->new_buff[y][x] != '\n'; x++)
            nb_o = fill_int_array(skbn, y, x, nb_o);
    }
    skbn->nb_o = nb_o;
}

void find_pos_player_annex(skb_t *skbn, int y, int x)
{
    if (skbn->new_buff[y][x] == 'P') {
        skbn->posP_y = y;
        skbn->posP_x = x;
    }
}

void find_pos_player(skb_t *skbn)
{
    skbn->posP_y = 0;
    skbn->posP_x = 0;

    for (int y = 0; skbn->new_buff[y] != NULL; y++) {
        for (int x = 0; skbn->new_buff[y][x] != '\n'; x++)
            find_pos_player_annex(skbn, y, x);
    }
}
