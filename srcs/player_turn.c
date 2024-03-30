#include "alcu.h"

static void draw_map(t_vector *v, int to_take)
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
                color_pair_index = 3;
            }

            attron(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
        }
    }
    refresh();
}

int player_turn(t_vector *v, int count_on_line)
{
    const char *format = "Please choose between 1 and %d items";

    int max_to_remove = min(3, count_on_line);
    int to_take = 1;
    while (1)
    {
        draw_map(v, to_take);

        int center = COLS / 2;
        int line = LINES - 2;
        mvprintw(line, center - ft_strlen(format) / 2, format, max_to_remove);

        int ch = getch();
        if (ch == 27 || ch == 'q' || ch == 'Q')
        {
            return END_OF_FILE;
        }
        else if (ch == KEY_UP)
        {
            to_take = min(to_take + 1, max_to_remove);
        }
        else if (ch == KEY_DOWN)
        {
            to_take = max(to_take - 1, 1);
        }
        else if (ch == KEY_ENTER || ch == KEY_RIGHT)
        {
            break;
        }
    }
    return to_take;
}
