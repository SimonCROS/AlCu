#include "alcu.h"

void draw_map(t_vector *v, int to_take, int to_take_color)
{
    int center_x = COLS / 2;

    for (size_t i = 0; i < v->count; i++)
    {
        int length = N(ft_vector_get(v, i));
        for (int j = 0; j < length; j++)
        {
            int col = center_x - length + (j * 2);
            int row = LINES - 3 - (v->count - i);
            int overflow = (length * 2) - COLS;
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
                col = COLS - (length - j) * 2;
            }
            if (col < 0)
            {
                continue;
            }
            if (overflow > 0)
            {
                mvprintw(row, 0, "%+d ", overflow);
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
                color_pair_index = to_take_color;
            }

            attron(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
        }
    }
}
