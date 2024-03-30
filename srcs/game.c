#include "alcu.h"

int game_loop(t_vector *v)
{
    int is_player_turn = 0;

    while (v->count > 0)
    {
        int count_on_line = ft_vector_get(v, v->count - 1);

        int choosen;
        // if (is_player_turn)
            choosen = player_turn(v, N(count_on_line));
        // else
        //     choosen = bot_turn(count_on_line);

        if (choosen == END_OF_FILE)
            return END_OF_FILE;

        count_on_line -= choosen;
        ft_vector_set(v, v->count - 1, count_on_line);
        if (N(count_on_line) == 0)
            v->count--;

        is_player_turn = !is_player_turn;
    }

    if (is_player_turn)
        ft_putendl("Player wins");
    else
        ft_putendl("AI wins");

    return EMPTY;
}
