/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** file fct
*/

#include "my.h"
#include "sokoban.h"

void find_size(skb_t *skbn)
{
    skbn->height = 0;
    skbn->len = 0;

    for (int i = 0; skbn->buff[i] != '\0'; i++) {
        if (skbn->buff[i] == '\n')
            skbn->height++;
    }
    for (; skbn->buff[skbn->len] != '\n'; skbn->len++);
}

static int invalid_cond(skb_t *skbn, int y, int x)
{
    if (skbn->len < 6 && skbn->new_buff[y][x] == 'X' &&
        skbn->new_buff[y + 1][x] == '#' && skbn->new_buff[y][x + 1] != 'O')
        return (84);
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y - 1][x] == '#' &&
    skbn->new_buff[y][x - 1] == '#')
        return (84);
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y + 1][x] == '#' &&
    skbn->new_buff[y][x + 1] == '#')
        return (84);
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y - 1][x] == '#' &&
    skbn->new_buff[y][x + 1] == '#')
        return (84);
    if (skbn->new_buff[y][x] == 'X' && skbn->new_buff[y + 1][x] == '#' &&
    skbn->new_buff[y][x - 1] == '#')
        return (84);
    return (0);
}

static int check_if_win_is_possible(skb_t *skbn)
{
    int x = 0;

    for (int y = 0; y != skbn->height;) {
        if (invalid_cond(skbn, y, x) == 84)
            return (84);
        if (x == skbn->len) {
            x = 0;
            y++;
        } else
            x++;
    }
    return (0);
}

static int check_if_valid(skb_t *skbn)
{
    int check_if_p_exist = 0;
    int check_x = 0;
    int check_o = 0;

    for (int i = 0; skbn->buff[i] != '\0'; i++) {
        if (skbn->buff[i] == 'P')
            check_if_p_exist++;
        if (skbn->buff[i] != 'P' && skbn->buff[i] != 'O' &&
        skbn->buff[i] != '#' && skbn->buff[i] != ' ' && skbn->buff[i] != 'X' &&
        skbn->buff[i] != '\n' && skbn->buff[i] != '\0')
            return (84);
        if (skbn->buff[i] == 'X')
            check_x++;
        if (skbn->buff[i] == 'O')
            check_o++;
    }
    if (check_if_p_exist != 1 || check_x != check_o)
        return (84);
    return (0);
}

int check_file(skb_t *skbn)
{
    struct stat size;
    skbn->buff = NULL;
    skbn->new_buff = NULL;
    stat(skbn->file, &size);
    skbn->buff = malloc(sizeof(char) * (size.st_size + 1));
    skbn->fd = open(skbn->file, O_RDONLY);
    if (skbn->fd == -1)
        return (84);
    read(skbn->fd, skbn->buff, size.st_size);
    skbn->buff[size.st_size] = '\0';
    if (check_if_valid(skbn) == 84)
        return (84);
    find_size(skbn);
    skbn->new_buff = my_str_to_word_array(skbn->buff);
    if (check_if_win_is_possible(skbn) == 84)
        return (84);
    find_pos_player(skbn);
    find_pos_o(skbn);
    close(skbn->fd);
    return (0);
}
