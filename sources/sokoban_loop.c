/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main fct
*/

#include "my.h"
#include "sokoban.h"

int recup_keys(skb_t *skbn)
{
    if (getch() == ' ') {
        endwin();
        return (1);
    }
    getch();
    switch (getch()) {
        case 'A':
            moove_up(skbn);
            break;
        case 'B':
            moove_down(skbn);
            break;
        case 'C':
            moove_right(skbn);
            break;
        case 'D':
            moove_left(skbn);
            break;
    }
    return (0);
}

void ini_colors(void)
{
    start_color();
    init_pair(1,COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    wbkgd(stdscr, COLOR_PAIR(1));
}

int start_sokoban(skb_t *skbn)
{
    keypad(stdscr, TRUE);
    noecho();
    initscr();
    while (1) {
        ini_colors();
        clear();
        refresh();
        curs_set(0);
        if (skbn->win == 0)
            draw_map(skbn);
        else
            draw_endings(skbn);
        if (recup_keys(skbn) == 1)
            return (0);
        win_or_loose(skbn);
        endwin();
    }
    return (0);
}
