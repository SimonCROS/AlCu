#include "alcu.h"

static int min(int a, int b)
{
    return a > b ? b : a;
}

int player_turn(int count_on_line)
{
    int max_to_remove = min(3, count_on_line);

    ft_putstr("Please choose between 1 and ");
    ft_putnbr(max_to_remove);
    ft_putendl(" items");
    int choosen = atoi_from_read(0, min(3, max_to_remove));
    while (choosen == ERROR || choosen == EMPTY)
    {
        ft_putendl("Invalid choice");
        choosen = atoi_from_read(0, min(3, max_to_remove));
    }

    if (choosen == END_OF_FILE)
        return END_OF_FILE;
    return choosen;
}
