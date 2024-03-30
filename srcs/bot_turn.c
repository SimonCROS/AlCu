#include <unistd.h>
#include "alcu.h"

static void draw_bot_map(t_vector *v, int to_take)
{
    clear();
    int center_x = COLS / 2;

    for (size_t i = 0; i < v->count; i++)
    {
        int length = N(ft_vector_get(v, i));
        for (int j = 0; j < length; j++)
        {
            int col = center_x - length / 2 + j;
            int row = LINES - 3 - (v->count - i);
            int overflow = length - COLS;
            int is_last_line = i == v->count - 1;
            int row_color_type = min(max(max(3 - (v->count - i - 1), 0), row), 3);
            int color_pair_index = 1;
            int dimmed = 0;
            char c = '|';

            if (row < 0)
            {
                continue;
            }
            if (overflow > 0)
            {
                col = COLS - (length - j);
                if (col < 3)
                {
                    c = '.';
                }
            }
            if (col < 0)
            {
                continue;
            }

            if (row_color_type == 0)
            {
                color_pair_index = 2;
                dimmed = 1;
            }
            if (row_color_type == 1)
            {
                color_pair_index = 2;
            }
            if (row_color_type == 2)
            {
                dimmed = 1;
            }
            if (row_color_type == 3 && is_last_line && j >= length - to_take)
            {
                color_pair_index = 4;
            }

            attron(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
        }
    }
}

int bot_turn(t_vector *v, int count_on_line)
{
    const char *format = "The bot takes %d items";
    int center = COLS / 2;
    int line = LINES - 2;
    int bot_take = 0;

	if (SHOULD_LOOSE(count_on_line))
	{
		if (N(count_on_line) % 4 == 0)
			bot_take = 1;
        else
		    bot_take = (N(count_on_line)) % 4;
	}
	else
	{
		if (N(count_on_line) % 4 == 1)
			bot_take = 1;
        else
		    bot_take = (N(count_on_line) - 1) % 4;
	}
    draw_bot_map(v, bot_take);
    mvprintw(line, center - ft_strlen(format) / 2, format, bot_take);
    refresh();
    usleep(750000);
	return (bot_take);
}

int find_strategy(t_vector *v)
{
    size_t    i;
    int     current;
    int     prev;

    prev = ft_vector_get(v, 0);
    i = 1;
    while (i < v->count)
    {
        current = ft_vector_get(v, i);
        if (SHOULD_LOOSE(prev))
            SET_SHOULD_LOOSE_FLAG(current, N(prev) % 4 != 1);
        else
            SET_SHOULD_LOOSE_FLAG(current, N(prev) % 4 == 1);
        ft_vector_set(v, i, current);
        prev = current;
        i++;
    }
    return (0);
}
