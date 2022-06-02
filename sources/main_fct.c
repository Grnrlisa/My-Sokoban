/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main fct
*/

#include "my.h"
#include "sokoban.h"

static void display_rules(void)
{
    my_putstr("USAGE\n      ./my_sokoban map\nDESCRIPTION       \n");
    my_putstr("     map file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n");
    my_putstr("     'P' for the player, 'X' for boxes and '0'");
    my_putstr("for storage locations.\n");
}

int main(int argc, char **argv)
{
    skb_t skbn;
    skbn.file = argv[1];
    skbn.win = 0;

    if (argc != 2)
        return (84);
    if (compare_strings("-h", skbn.file) == 0)
        display_rules();
    if (check_file(&skbn) == 84)
        return (84);
    else
        start_sokoban(&skbn);
    free(skbn.new_buff);
    return (0);
}
