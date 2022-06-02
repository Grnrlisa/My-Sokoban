/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main fct
*/

#include "my.h"
#include "sokoban.h"

int check_col_left(skb_t *skbn)
{
    if ((skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] == 'X' &&
    skbn->new_buff[skbn->posP_y][skbn->posP_x - 2] == 'X' &&
    skbn->new_buff[skbn->posP_y][skbn->posP_x - 3] == '#'))
        return (0);
    if ((skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] == 'X' &&
    skbn->new_buff[skbn->posP_y][skbn->posP_x - 2] == '#'))
        return (0);
    if (skbn->new_buff[skbn->posP_y][skbn->posP_x - 1] != '#')
        return (1);
    return (0);
}

int check_col_right(skb_t *skbn)
{
    if ((skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] == 'X' &&
    skbn->new_buff[skbn->posP_y][skbn->posP_x + 2] == 'X' &&
    skbn->new_buff[skbn->posP_y][skbn->posP_x + 3] == '#'))
        return (0);
    if ((skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] == 'X' &&
    skbn->new_buff[skbn->posP_y][skbn->posP_x + 2] == '#'))
        return (0);
    if (skbn->new_buff[skbn->posP_y][skbn->posP_x + 1] != '#')
        return (1);
    return (0);
}

int check_col_down(skb_t *skbn)
{
    if ((skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] == 'X' &&
    skbn->new_buff[skbn->posP_y + 2][skbn->posP_x] == 'X' &&
    skbn->new_buff[skbn->posP_y + 3][skbn->posP_x] == '#'))
        return (0);
    if ((skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] == 'X' &&
    skbn->new_buff[skbn->posP_y + 2][skbn->posP_x] == '#'))
        return (0);
    if (skbn->new_buff[skbn->posP_y + 1][skbn->posP_x] != '#')
        return (1);
    return (0);
}

int check_col_up(skb_t *skbn)
{
    if ((skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] == 'X' &&
    skbn->new_buff[skbn->posP_y - 2][skbn->posP_x] == 'X' &&
    skbn->new_buff[skbn->posP_y - 3][skbn->posP_x] == '#'))
        return (0);
    if ((skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] == 'X' &&
    skbn->new_buff[skbn->posP_y - 2][skbn->posP_x] == '#'))
        return (0);
    if (skbn->new_buff[skbn->posP_y - 1][skbn->posP_x] != '#')
        return (1);
    return (0);
}
