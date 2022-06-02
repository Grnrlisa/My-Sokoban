/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main fct
*/

#include "my.h"
#include "sokoban.h"

void draw_map(skb_t *skbn)
{
    int l = (skbn->len / 2);
    int h = (skbn->height / 2);

    for (int i = 0; skbn->new_buff[i] != NULL; i++) {
        attron(COLOR_PAIR(2));
        mvprintw((LINES / 2) - l + i, (COLS / 2) - h, skbn->new_buff[i]);
        attroff(COLOR_PAIR(2));
    }
}

void draw_endings(skb_t *skbn)
{
    if (skbn->win == 1) {
        attron(COLOR_PAIR(2));
        mvprintw((LINES / 2), (COLS / 2) - 6, "You win :-)");
        attroff(COLOR_PAIR(2));
    }
    if (skbn->win == 2) {
        attron(COLOR_PAIR(2));
        mvprintw((LINES / 2), (COLS / 2) - 6, "You loose :-(");
        attroff(COLOR_PAIR(2));
    }
}
