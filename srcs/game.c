#include "alcu.h"

static void print_strategy(t_vector *v) // REMOVE
{
    size_t i;
    int current;

    i = 0;
    while (i < v->count)
    {
        current = ft_vector_get(v, i);
        ft_putnbr(current & 0x7FFFFFFF);
        if (current < 0)
            write(1, " | 1", 4);
        else
            write(1, " | 0", 4);
        write(1, "\n", 1);
        i++;
    }
    write(1, "\n", 1);
}

int game_loop(t_vector *v)
{
    int is_player_turn = 0;

    print_strategy(v);

    while (v->count > 0)
    {
        int count_on_line = ft_vector_get(v, v->count - 1);

        int choosen;
        if (is_player_turn)
            choosen = player_turn(N(count_on_line));
        else
            choosen = bot_turn(count_on_line);

        if (choosen == END_OF_FILE)
            return END_OF_FILE;

        count_on_line -= choosen;
        ft_vector_set(v, v->count - 1, count_on_line);
        if (N(count_on_line) == 0)
            v->count--;

        print_strategy(v);

        is_player_turn = !is_player_turn;
    }

    if (is_player_turn)
        ft_putendl("Player wins");
    else
        ft_putendl("AI wins");

    return EMPTY;
}
